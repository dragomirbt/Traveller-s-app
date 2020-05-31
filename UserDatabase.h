#ifndef USERDATABASE_HEADER_INCLUDED
#define USERDATABASE_HEADER_INCLUDED
#include "User.h"
#include <vector>
/// класът описва масив от потребители (User)
///
/// член - данни:
///		 - масив от потребители (User)
class Userdatabase
{
private:
	vector<User> users;
public:
	/// добавя потребител към базата данни от потребители
	/// @param u потребител, който се добавя
	void addToUserdatabase(User& u);
	/// проверява дали потребител е в базата данни от потребители
	/// @param username потребителско име на потребител
	/// @param password парола на потребител
	bool chekIfUserIsInDatabase(const char* username, const char* password) const; 
};
#endif