#ifndef USER_HEADER_INCLUDED
#define USER_HEADER_INCLUDED
#include <vector>
#include <string>
#include "Trip.h"
const int MAX_SIZE = 20;

/// ������ ������ ������������, ����� ������� ���� ����������
///
/// ���� - �����:
///		 - ������������� ���
///	 	- ������
///		- ����� �����
///		- ����� ���� �����
///		- ��������
class User
{
private:
	char username[MAX_SIZE];
	char password[MAX_SIZE];
	char email_address[MAX_SIZE + 5];
	vector<Trip> personal_database;
	vector<string> friends;
	/// �������, ����� ��������� ���� ����� ����������� �� ��������
	/// @param friend_username ������������� ��� �� ��������
	bool chekIfTheyAreFriends(const char* friend_username) const;
public:
	/// ����������� �� ������������
	User();
	/// ����������� � ���������
	User(const char* username,const char* password, const char* email_address);
	/// ������� ��������������� ���
	/// @param username ������������� ���
	void setUsername(const char* username);
	/// @returns const char* ������������� ���
	const char* getUsername() const;
	/// @returns const char* ������
	const char* getPassword() const;
	/// @returns const char* ����� �����
	const char* getEmailAddress() const;
	/// ������� �������� � ����� ���� ����� �� �����������
	/// @param t ��������
	/// @param destination ����������
	/// @param from ������ �� ����������
	/// @param to ���� �� ����������
	/// @param mark ������
	/// @param comment ��������
	/// @param images ������
	bool createTrip(Trip& t, const char* destination, Date from, Date to, unsigned mark, const char* comment, vector<string> images);
	/// ������ �������� � ������� ���� ����� �� �����������
	/// @param trip ��������
	void setTripToPersonalDatabase(Trip& trip);
	/// ������� ������� ���� ����� �� ������� �� �����������
	/// @param friend_username ������������� ��� �� ��������
	void printFriendPersonalDatabase(const char* friend_username) const;
	/// ������� ������� ���� ����� �� �����������
	/// @param username ������������� ��� 
	void printPersonalDatabaseInformation(const char* username) const;
	/// ������ ������� � ������ �� ��������
	/// @param friend_username ������������� ��� �� ��������, ����� ������ �� �������
	void addFriend(string friend_username);
	/// ������� ������ � ���������� �� �����������
	void printFriendList() const;
	/// ������� �������� �� ������ ����������
	/// @param destination ����������, �� ����� �� �� ������ ������������
	void checkDestinationMarks(const char* destination) const;
	/// ������ ����������, ������������� ��� � ������ � ������ ����� �� ������������
	/// @param destination ����������
	/// @param username ������������� ���
	/// @param mark ������
	bool addDestination(const char* destination, const char* username, unsigned mark) const;
};


#endif