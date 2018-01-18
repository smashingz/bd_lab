#include "connection.hpp"

Connection::Connection(std::string host, std::string login, std::string password, std::string db_name) {
	this->host = host;
	this->login = login;
	this->password = password;
	this->db_name = db_name;
	conn = this->connect();
}

&Connection Connection::connect() {
	std::ostringstream conn_policy;
	conn_policy << "host=" << this->host 
		<< " user=" << this->login
		<< " password=" << this->password
		<< " dbname=" << this->db_name;
	pqxx::connection conn(conn_policy.str());
	return &conn;
}
