#include "db.h"
#include <vector>
#include <limits>
#include <string>
#include <iostream>
using namespace std;

int main() 
{
	string database1 = "Video Games";
	string username1 = "rickFlair";
	string password1 = "hello123";
	bool connection1;

	string database2 = "TV Shows";
	string username2 = "johnHanvey";
	string password2 = "alaska123";
	bool connection2;

	try 
	{
		Database& dbInstance1 = Database::getInstance(database1, username1, password1, connection1);
		dbInstance1.printInformation();
		Database& dbInstance2 = Database::getInstance(database2, username1, password1, connection1);
	}
	catch (runtime_error& e) 
	{
		cerr << "Error: " << e.what() << endl;
		return 1;
	}

	return 0;
}