#include <pqxx/connection>
#include <pqxx/transaction>
#include <iostream>
#include <cstring>

int main() {
	const std::string DB_NAME = "hostels";
	const std::string HOST = "localhost";
	const std::string QUERY = "SELECT * FROM hostel";
	std::string login, password;
	std::cout << "Логин: ";
	std::cin >> login;
	std::cout << "Пароль: ";
	std::cin >> password;
	std::ostringstream conn_policy;
	conn_policy << "host=" << HOST 
		<< " user=" << login
		<< " password=" << password
		<< " dbname=" << DB_NAME;
	try {
		pqxx::connection conn(conn_policy.str());
		pqxx::work act(conn, "SampleSelect");	
		pqxx::result res = act.exec(QUERY);
		if (!res.size()) {
                   std::cout << "Empty result set." << std::endl;
                   return 0;
		}
		for (auto i: res) {
			for (auto j: i) {
				std::cout << j << "\t";
			}
				std::cout << std::endl;
		}
	} catch(pqxx::pqxx_exception &e) {
		std::cerr << e.base().what() << std::endl;
	}
	return 0;
}
