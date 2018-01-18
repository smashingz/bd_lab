#include "connection.hpp"
#include <string>

Connection::Connection(std::string host, std::string login, std::string password, std::string db_name) {
	std::ostringstream conn_policy;
	conn_policy << "host=" << host 
		<< " user=" << login
		<< " password=" << password
		<< " dbname=" << db_name;
	this = pqxx::connection(conn_policy.str());
}
