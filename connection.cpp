#include "connection.hpp"

Connection::Connection(std::string host, std::string login, std::string password, std::string db_name) {
	this->host = host;
	this->login = login;
	this->password = password;
	this->db_name = db_name;
}

Connection::~Connection() {}

void Connection::connect() {
	std::ostringstream conn_policy("");
	conn_policy << "host=" << host 
		<< " user=" << login
		<< " password=" << password
		<< " dbname=" << db_name;
	pqxx::connection huy(conn_policy.str());
	conn = huy;
}
