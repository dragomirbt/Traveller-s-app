#include "Date.h"
#include <iostream>
using namespace std;

const int curr_year = 2020;
Date::Date()
{
	day = 1;
	month = 1;
	year = 2020;
}
Date::Date(int day, int month, int year)
{
	if (isValidDate(year, month, day))
	{
		this->day = day;
		this->month = month;
		this->year = year;
	}
}
Date& Date::operator=(const Date& other)
{
	if (this != &other)
	{
		this->day = other.day;
		this->month = other.month;
		this->year = other.year;
	}
	return *this;
}
bool Date::isLeap(int year) const
{
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}
bool Date::isValidDate(int year, int month, int day) const
{
	if (year < curr_year)
	{
		cout << "The year is unvalid\n";
		return false;
	}
	if (month < 1 || month >12)
	{
		cout << "The month is unvalid\n";
		return false;
	}
	if (day < 1 || day>31)
	{
		cout << "The day is unvalid\n";
		return false;
	}
		
	if (month == 2)
	{
		if (isLeap(year))
		{
			if (day > 29)
			{
				cout << "The day is unvalid\n";
				return false;
			}
		}
		else
		{
			if (day > 28);
			{
				cout << "The day is unvalid\n";
				return false;
			}
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30)
		{
			cout << "The day is unvalid\n";
			return false;
		}
	}
	return true;
}
void Date::printDate() const
{
	cout << day << '.' << month << '.' << year << endl;
}
void Date::setDay(int day)
{
	this->day = day;
}
void Date::setMonth(int month)
{
	this->month = month;
}
void Date::setYear(int year)
{
	this->year = year;
}
ostream& operator<<(ostream& o, Date const& d) 
{
	return o << d.day << '.' << d.month << '.' << d.year;
}
istream& operator>>(istream& i, Date& d) {
	char c;
	return i >> d.day >> c >> d.month >> c >> d.year;
}
bool Date::operator>(const Date& other) const
{
	if (year > other.year)
		return false;
	if (month > other.month)
		return false;
	if (day > other.day)
		return false;

	return true;
}