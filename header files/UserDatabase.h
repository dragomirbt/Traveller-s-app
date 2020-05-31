#ifndef USERDATABASE_HEADER_INCLUDED
#define USERDATABASE_HEADER_INCLUDED
#include "User.h"
#include <vector>
/// ������ ������ ����� �� ����������� (User)
///
/// ���� - �����:
///		 - ����� �� ����������� (User)
class Userdatabase
{
private:
	vector<User> users;
public:
	/// ������ ���������� ��� ������ ����� �� �����������
	/// @param u ����������, ����� �� ������
	void addToUserdatabase(User& u);
	/// ��������� ���� ���������� � � ������ ����� �� �����������
	/// @param username ������������� ��� �� ����������
	/// @param password ������ �� ����������
	bool chekIfUserIsInDatabase(const char* username, const char* password) const; 
};
#endif