#ifndef DB_H
#define DB_H
#include <string>
using namespace std;

class Database 
{
private:
	// Constructor needs to be private, to prevent object creation
	Database(const string& db, const string& un, const string& pw, time_t last_activity);
	time_t last_activity;
	static const int TIMEOUT{ 5 };
	static Database* instance;

	string db;
	string username;
	string password;
	bool connected = false;

public:
	~Database();
	// Retrive the single instance of the object
	static Database* getInstance(const string& new_db, const string& new_username, const string& new_password, time_t last_activity);
	// To prevent copying and assignment since there is no need for this application
	Database(const Database&);
	Database& operator=(const Database&);
	Database(Database&&) noexcept(false);
	Database& operator=(const Database&&) noexcept(false);

	void connect();

	void disconnect();

	bool isConnected();

	bool isTimeout();

	void refreshConnection();

	void set_username(const string& newUN);

	void set_password(const string& newPW);

	string get_username();

	string get_password();

	static void resetInstance();

	void printInformation();

	void* operator new(size_t size);

	void operator delete(void*);
};

#endif // DB_H