#include "User.h"
#include "Trip.h"
#include "UserDatabase.h"
#include <iostream>
using namespace std;

string ext;
string getExtention(string image)
{
	ext = "";
	int i = 0;
	while (image[i] != '\0')
	{
		if (image[i] == '.')
		{
			i++;
			while (image[i] != '\0')
			{
				ext.push_back(image[i]);
				i++;
			}
			break;
		}
		i++;
	}
	return ext;
}
string& deleteExtention(string& image)
{
	int size = image.size();
	while (image[size - 1] != '.')
	{
		image.pop_back();
		size--;
	}
	return image;
}
void isValidImageExtention(vector<string> images)
{
	int size = images.size();
	string extention;
	int count_invalid_extentions = 0;
	for (int i = 0; i < size; i++)
	{
		extention = getExtention(images[i]);
		if (extention.compare("jpeg") != 0 && extention.compare("png") != 0)
		{
			images[i] = deleteExtention(images[i]);
			images[i].push_back('p');
			images[i].push_back('n');
			images[i].push_back('g');
			count_invalid_extentions++;
		}
	}
	if (count_invalid_extentions != 0)
		cout << "The extentions of all images must be .jpeg or .png, so the worng ones were set to png\n";
}
vector<string> isValidImageName(vector<string>& images)
{
	int count_incorrect_symbols = 0;
	int size = images.size();
	for (int i = 0; i < size; i++)
	{
		int word_size = images[i].size();
		for (int j = 0; j < word_size; j++)
		{
			if (images[i][j] == '.')
				break;
			if (!((images[i][j] >= 'a' && images[i][j] <= 'z')
			|| (images[i][j] >= 'A' && images[i][j] <= 'Z') 
			|| images[i][j] == '_'))
			{
				images[i][j] = 'a';
				count_incorrect_symbols++;
			}
		}
	}
	if (count_incorrect_symbols != 0)
		cout << "The name of a photo was invalid so all incorrect symbols were set to 'a'\n";
	return images;
}

int main()
{
	//start of the program
	cout << "Log in or Register\n";
	Userdatabase us;
	char start[MAX_SIZE];
	cin.getline(start, MAX_SIZE);
	if (!(strcmp(start, "Log in")) || !(strcmp(start, "log in")))
	{
		cout << "Enter username and password:\n";
		char username[MAX_SIZE];
		char password[MAX_SIZE];
		cin.getline(username, MAX_SIZE);
		cin.getline(password, MAX_SIZE);
		if(us.chekIfUserIsInDatabase(username, password));
		{
			User u;
			u.printPersonalDatabaseInformation(username);
		}
	}
	else if (!(strcmp(start, "Register")) || !(strcmp(start, "register")))
	{
		cout << "Enter username, password and email address:\n";
		char username[MAX_SIZE];
		char password[MAX_SIZE];
		char email[MAX_SIZE + 5];
		cin.getline(username, MAX_SIZE);
		cin.getline(password, MAX_SIZE);
		cin.getline(email, MAX_SIZE + 5);
		cout << "Your registration was successful\n";
		User u(username, password, email);
		us.addToUserdatabase(u);
		Trip t;
		cout << "Would you like to add a trip?\n";
		cout << "y/n\n";
		char vote[2];
		cin.getline(vote,2);
		while(!strcmp(vote,"y"))
		{
			char destination[MAX_DEST_SIZE];
			Date from, to;
			char comment[MAX_COM_SIZE];
			unsigned mark;
			vector<string> images;
			cout << "Enter destination\n";
			cin.getline(destination, MAX_DEST_SIZE);
			cout << "Enter period from-to\n";
			cin >> from >> to;
			cout << "Enter your mark\n";
			cin >> mark;
			cin.ignore();
			u.addDestination(destination, username, mark);
			cout << "Enter your comment\n";
			cin.getline(comment, MAX_COM_SIZE);
			cout << "How much images are you going to add?\n";
			int number;
			cin >> number;
			string image;
			for (int i = 0; i < number; i++)
			{
				cin >> image;
				images.push_back(image);
			}
			isValidImageExtention(images);
			images = isValidImageName(images);
			u.createTrip(t, destination, from, to, mark, comment, images);
			u.setTripToPersonalDatabase(t);
			cout << "Would you like to add a trip?\n";
			cout << "y/n\n";
			cin.ignore();
			cin.getline(vote, 2);
		}
		cout << "Would you like to add a freind?\n";
		cout << "y/n\n";
		cin.getline(vote, 2);
		while (!strcmp(vote, "y"))
		{
			cout << "Enter the username of your friend\n";
			char username[MAX_SIZE];
			cin.getline(username, MAX_SIZE);
			u.addFriend(username);
			cout << "Would you like to add another freind?\n";
			cout << "y/n\n";
			cin.getline(vote, 2);
		}
		cout << "Would you like to see where your friend had travelled?\n";
		cout << "y/n\n";
		cin.getline(vote, 2);
		while (!strcmp(vote, "y"))
		{
			cout << "Enter the username of your friend\n";
			char username[MAX_SIZE];
			cin.getline(username, MAX_SIZE);
			u.printFriendPersonalDatabase(username);
			cout << "Would you like to see another friend's trip?\n";
			cout << "y/n\n";
			cin.getline(vote, 2);
		}
		cout << "Would you like to see a destination review?\n";
		cout << "y/n\n";
		cin.getline(vote, 2);
		while (!strcmp(vote, "y"))
		{
			cout << "Enter a destination\n";
			char destination[MAX_SIZE];
			cin.getline(destination, MAX_SIZE);
			u.checkDestinationMarks(destination);
			cout << "Would you like to see another destination review?\n";
			cout << "y/n\n";
			cin.getline(vote, 2);
		}
	}
	return 0;
}