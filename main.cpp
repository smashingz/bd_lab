#include <pqxx/transaction>
#include <pqxx/result>
#include <iostream>
#include <iomanip>

void print_query_res(pqxx::result r);

int main() {
	std::cout << "Логин: ";
	std::cin >> login;
	std::cout << "Пароль: ";
	std::cin >> password;
	try {
		pqxx::work act(conn, "SampleSelect");	
		pqxx::result res = act.exec(QUERY);
		if (!res.size()) {
                   std::cout << "Empty result set." << std::endl;
                   return 0;
		}
	print_query_res(res);
	} catch(pqxx::pqxx_exception &e) {
		std::cerr << e.base().what() << std::endl;
	}
	return 0;
}

void print_query_res(pqxx::result r) {
		int n = 0, sum = 0;
		std::vector<int> widths(r.columns());
		for(pqxx::tuple::size_type i = 0; i < r.columns(); i++) {
			widths[i] = std::string(r.column_name(i)).length();
		}
		for (auto i: r) {
			for (auto j: i) {
				if(pqxx::to_string(j).length() > widths[n]) {
					widths[n] = std::string(pqxx::to_string(j)).length();
				}
				n++;
			}
			n = 0;
		}
		for(int i = 0; i < r.columns(); i++) {
			std::cout << "|" << std::setw(widths[i]) << std::left << r.column_name(i) << " ";
		}
		std::cout << std::endl;
		for(auto i: widths) {
			sum += i;
		}
		std::cout << std::setfill('-') << std::setw(sum) << "-" << std::endl;
		std::cout << std::setfill(' ');
		n = 0;
		for (auto i: r) {
			for (auto j: i) {
				std::cout << "|" << std::setw(widths[n++]) << std::left << j << " ";
			}
				std::cout << std::endl;
				n = 0;
		}
}
