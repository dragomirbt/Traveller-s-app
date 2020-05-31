#ifndef USER_HEADER_INCLUDED
#define USER_HEADER_INCLUDED
#include <vector>
#include <string>
#include "Trip.h"
const int MAX_SIZE = 20;

/// класът описва информацията, която съдържа един потребител
///
/// член - данни:
///		 - потребителско име
///	 	- парола
///		- имейл адрес
///		- лична база данни
///		- приятели
class User
{
private:
	char username[MAX_SIZE];
	char password[MAX_SIZE];
	char email_address[MAX_SIZE + 5];
	vector<Trip> personal_database;
	vector<string> friends;
	/// функция, която проверява дали двама потребителя са приятели
	/// @param friend_username потребителско име на приятеля
	bool chekIfTheyAreFriends(const char* friend_username) const;
public:
	/// конструктор по подразбиране
	User();
	/// конструктор с параметри
	User(const char* username,const char* password, const char* email_address);
	/// променя потребителското име
	/// @param username потребителско име
	void setUsername(const char* username);
	/// @returns const char* потребителско име
	const char* getUsername() const;
	/// @returns const char* парола
	const char* getPassword() const;
	/// @returns const char* имейл адрес
	const char* getEmailAddress() const;
	/// създава пътуване и лична база данни на потребителя
	/// @param t пътуване
	/// @param destination дестинация
	/// @param from начало на пътуването
	/// @param to край на пътуването
	/// @param mark оценка
	/// @param comment коментар
	/// @param images снимки
	bool createTrip(Trip& t, const char* destination, Date from, Date to, unsigned mark, const char* comment, vector<string> images);
	/// добавя пътуване в личната база данни на потребителя
	/// @param trip пътуване
	void setTripToPersonalDatabase(Trip& trip);
	/// извежда личната база данни на приятел на потребителя
	/// @param friend_username потребителско име на приятеля
	void printFriendPersonalDatabase(const char* friend_username) const;
	/// извежда личната база данни на потребителя
	/// @param username потребителско име 
	void printPersonalDatabaseInformation(const char* username) const;
	/// добавя приятел в масива от приятели
	/// @param friend_username потребителско име на приятеля, който искаме да добавим
	void addFriend(string friend_username);
	/// извежда списък с приятелите на потребителя
	void printFriendList() const;
	/// извежда оценките за дадена дестинация
	/// @param destination дестинация, за която да се изведе информацията
	void checkDestinationMarks(const char* destination) const;
	/// добавя дестинация, потребителско име и оценка в базата данни на дестинациите
	/// @param destination дестинация
	/// @param username потребителско име
	/// @param mark оценка
	bool addDestination(const char* destination, const char* username, unsigned mark) const;
};


#endif