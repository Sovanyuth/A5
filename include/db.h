#ifndef DB_H
#define DB_H
#include <string>
using namespace std;

// Creating a class movie 
class DataBase 
{
private:
	// Constructor needs to be private, to prevent object creation
	DataBase(const string& db, const string& un, const string& pw, const bool& connected);
	~DataBase() {}
	static DataBase* instance;

	string db;
	string username;
	string password;
	bool connected;

public:
	// Retrive the single instance of the object
	static DataBase& getInstance(const string& new_db, const string& new_username, const string& new_password, const bool& new_con);
	// To prevent copying and assignment since there is no need for this application
	DataBase(const DataBase&) = delete;
	DataBase& operator=(const DataBase&) = delete;

	void connect();

	void disconnect();

	bool status();

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