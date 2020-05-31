#include "User.h"
#include <iostream>
User::User()
{
	strcpy(username, "");
	strcpy(password, "");
	strcpy(email_address, "");
}
User::User(const char* username, const char* password, const char* email_address)
{
	strcpy(this->username, username);
	strcpy(this->password, password);
	strcpy(this->email_address, email_address);
}
bool User::createTrip(Trip& t, const char* destination, Date from, Date to, unsigned mark, const char* comment, vector<string> images)
{
	t.createTrip(t, destination, from, to, mark, comment, images);
	char USERNAME[MAX_SIZE];
	strcpy(USERNAME, username);
	ofstream file(strcat(USERNAME, ".db"), ios::out | ios::app);
	if (!file)
	{
		cout << "Cannot open file\n";
		return 0;
	}
	file << destination << "		" << from << "  " << to << "		" << mark << "		" << comment<<"		";
	int size = images.size();
	for (int i = 0; i < size; i++)
	{
		file << images[i];
		if (i < size - 1)
			file << ", ";
	}
	file << endl;
	file.close();
	return 1;
}
void User::setUsername(const char* username)
{
	strcpy(this->username, username);
}
const char* User::getUsername() const
{
	return username;
}
const char* User::getPassword() const
{
	return password;
}
const char* User::getEmailAddress() const
{
	return email_address;
}
void User::setTripToPersonalDatabase(Trip& trip)
{
	this->personal_database.push_back(trip);
}
void User::addFriend(string friend_username)
{
	friends.push_back(friend_username);
}
bool User::chekIfTheyAreFriends(const char* friend_username) const
{
	int size = friends.size();			
	for (int i = 0; i < size; i++)
		if (friends[i].compare(friend_username) == 0)
			return 1;
	return 0;
}
void User::printFriendPersonalDatabase(const char* friend_username) const 
{
	if (chekIfTheyAreFriends(friend_username))
	{
		int size = friends.size();
		string info;
		char FRIEND_USERNAME[MAX_SIZE];
		strcpy(FRIEND_USERNAME, friend_username);
		char c;
		for (int i = 0; i < size; i++)
		{
			if (friends[i].compare(FRIEND_USERNAME) == 0)
			{
				ifstream file(strcat(FRIEND_USERNAME, ".db"), ios::in);
				if (file)
				{
					while (true)
					{
						file >> info;
						if (file.eof())
							break;
						cout << info << " ";
						file.get(c);
						if (c == '\n')
							cout << endl;
					}
				}
				else
					cout << "Cannot load User's personal database\n";
				file.close();
				break;
			}
		}
	}
	else
		cout << "They are not friends\n";
}
void User::printPersonalDatabaseInformation(const char* username) const
{
	string info;
	char USERNAME[MAX_SIZE];
	strcpy(USERNAME, username);
	char c;
		ifstream file(strcat(USERNAME, ".db"), ios::in);
		if (file)
		{
			while (true)
			{
				file >> info;
				if (file.eof())
					break;
				cout << info << " ";
				file.get(c);
				if (c == '\n')
					cout << endl;
			}
		}
		else
			cout << "Cannot load User's personal database\n";
		file.close();
}
void User::printFriendList() const
{
	int size = friends.size();
	for (int i = 0; i < size; i++)
		cout << friends[i] << endl;
}
void User::checkDestinationMarks(const char* destination) const
{
	ifstream file("destinations.db", ios::in);
	char dest[MAX_DEST_SIZE];
	char username[MAX_SIZE];
	unsigned mark;
	char c;
	if (file)
	{
		while (true)
		{
			if (file.eof())
				break;
			file >> dest;
			if (!(strcmp(dest, destination)))
			{
				file >> username;
				file >> mark;
				cout << "user: " << username << ", mark: " << mark << endl;
			}
			else
			{
				file.get(c);
				while (c != '\n')
				{
					file.get(c);
				}
			}
		}
	}
}
bool User::addDestination(const char* destination, const char* username, unsigned mark) const
{
	ofstream file("destinations.db", ios::out | ios::app);
	if (!file)
	{
		cout << "Cannot open file\n";
		return 0;
	}
	file << destination << "	" << username << "		" << mark << endl;
	return 1;

}
