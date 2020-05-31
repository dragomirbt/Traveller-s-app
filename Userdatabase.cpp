#include "Userdatabase.h"
#include <iostream>
void Userdatabase::addToUserdatabase(User& u)
{
	ofstream file("users.db", ios::out | ios::app);
	if (file)
		file << u.getUsername() << "	" << u.getPassword() << "	" << u.getEmailAddress() << endl;
	else
		cout << "Cannot add to users.db\n";
	file.close();
	users.push_back(u);
}
bool Userdatabase::chekIfUserIsInDatabase(const char* username, const char* password) const
{
	ifstream file("users.db", ios::in);
	char info[MAX_SIZE];
	if (file)
	{
		while (!file.eof())
		{
			file >> info;
			if (!(strcmp(info, username)))
			{
				file >> info;
				if (!strcmp(info, password))
				{
					cout << "Log in successful\n";
					file.close();
					return 1;
				}
			}
		}
		cout << "Incorect username or password\n";
	}
	else
		cout << "Cannot load users database\n";
	return 0;

}