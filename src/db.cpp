#include "db.h"
#include <string>
#include <iostream>
#include <memory>
#include<stdexcept>
#include <new>
using namespace std;

// Initializing the instance class to be nullptr 
Database* Database::instance = nullptr;

// Using initializer for the constructor
Database::Database(const string& db, const string& un, const string& pw)
    : db(db), username(un), password(pw) {}

Database::~Database() {
    if (connected) 
    {
        disconnect();
    }
}

// Creates and returns the instance of the Database
Database* Database::getInstance(const string& new_db, const string& new_username, const string& new_password)
{
    // Calling for the first time: this will set username and password
    if (instance == nullptr) 
    {
        instance = new Database(new_db, new_username, new_password);
    }
    /* However, subsequent time, it matches the Database NAME, USERNAME, and PASSWORD
    -> returns the previous instance */ 
    else 
    {
        if (new_db != instance->db || new_username != instance->username || new_password != instance->password)
        {
           throw runtime_error("Invalid Database name, username or password");
        }
    }

    return instance;
}

// Using malloc to get the size needed to allocate the memory
void* Database::operator new(size_t size)
{
    cout << "overloaded new ";
    void* ptr = malloc(sizeof(size));

    if (!ptr) throw bad_alloc();
    return ptr;
}

// Delete is just "free" the memory
void Database::operator delete(void* ptr)
{
    cout << "overloaded delete ";
    free(ptr);
}

void Database::connect()
{
    instance->connected = true;
}

void Database::disconnect()
{
    instance->connected = false;
}

bool Database::isConnected()
{
    return instance->connected;
}

void Database::set_username(const string& newUN)
{
    instance->username = newUN;
}

void Database::set_password(const string& newPw)
{
    instance->password = newPw;
}

string Database::get_username()
{
    return instance->username;
}

string Database::get_password()
{
    return instance->password;
}

void Database::resetInstance()
{
    if (instance != nullptr)
    {
        delete instance;
        instance = nullptr;
    }
}

// Used only for debugging purposes
void Database::printInformation() 
{   
    cout << "Accessing the instance's information..." << endl;
    cout << "Database: " << instance->db << endl;
    cout << "Username: " << instance->username << endl;
    cout << "Password: " << instance->password << endl;

    if (instance->connected == 0) 
    {
        cout << "Connection Status: false" << endl;
    }
    else 
    {
        cout << "Connection Status: true" << endl;
    }
}