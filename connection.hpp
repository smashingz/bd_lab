#include <pqxx/connection>

class Connection {
	private:
		std::string login;
		std::string password;
		std::string db_name;
		std::string host;
		pqxx::connection& conn;
		//std::string query = "SELECT * FROM hostel";
	public:	
		Connection(std::string host, std::string login, std::string password, std::string db_name);
		~Connection();
		void connect();
};
