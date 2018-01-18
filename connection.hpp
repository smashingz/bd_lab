#include <pqxx/connection>
#include <string>

class Connection: public pqxx::connection {
	std::string login;
	std::string password;
	std::string db_name;
	std::string host;
	//std::string query = "SELECT * FROM hostel";
	
	Connection(std::string host, std::string login, std::string password, std::string db_name);
};
