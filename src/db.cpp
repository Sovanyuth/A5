#include "db.h"
#include <string>
#include <iostream>
#include <memory>
using namespace std;

DataBase* DataBase::instance = nullptr;

DataBase::DataBase(const string& db, const string& un, const string& pw, const bool& connected)
    : db(db), username(un), password(pw), connected(false) {}

// Creates and returns the instance of the database
DataBase& DataBase::getInstance(const string& new_db, const string& new_username, const string& new_password, const bool& new_con)
{
    // Calling for the first time: this will set username and password
    if (instance == nullptr) 
    {
        cout << "New Instance is Created" << endl;
        instance = new DataBase(new_db, new_username, new_password, new_con);
    }
    /* However, subsequent time, it matches the DATABASE NAME, USERNAME, and PASSWORD
    -> returns the previous instance */ 
    else 
    {
        if (new_db != instance->db || new_username != instance->username || new_password != instance->password)
        {
           throw runtime_error("Invalid database name, username or password");
        }
    }

    return *instance;
}


void DataBase::connect()
{
    instance->connected = true;
}

void DataBase::disconnect()
{
    instance->connected = false;
}

bool DataBase::status()
{
    return instance->connected;
}

void DataBase::set_username(const string& newUN)
{
    instance->username = newUN;
}

void DataBase::set_password(const string& newPw)
{
    instance->password = newPw;
}

string DataBase::get_username()
{
    return instance->username;
}

string DataBase::get_password()
{
    return instance->password;
}

void DataBase::resetInstance()
{
    if (instance != nullptr)
    {
        cout << "Instance has been resetted!" << endl;
        delete instance;
        instance = nullptr;
    }
}

void DataBase::printInformation() 
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

void* DataBase::operator new(size_t size)
{
    cout << "Overloaded new" << endl;
    void* ptr = malloc(sizeof(size));

    if (!ptr) throw bad_alloc();
    return ptr;
}

void DataBase::operator delete(void* ptr)
{
    cout << "Overloaded delete" << endl;
    free(ptr);
}