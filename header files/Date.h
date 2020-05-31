#ifndef DATE_HEADER_INCLUDED
#define DATE_HEADER_INCLUDED
#include <fstream>
using namespace std;

/// класът описва информацията, която описва една дата
///
/// класът е създаден с цел подобрение на проекта
///
/// член - данни:
///      - ден
///      - месец
///      - година
class Date
{
private:
	int day;
	int month;
	int year;

	/// проверява дали една година е високосна
	/// @param year годината, която се проверява
	bool isLeap(int year) const;
	/// проверява дали една дата е валидна
	/// @param year година
	/// @param month месец
	/// @param day ден
	bool isValidDate(int year, int month, int day) const;
public:
	/// конструктор по подразбиране
	Date();
	/// конструктор с параметри
	Date(int day, int month, int year);
	/// предефиниран оператор =
	Date& operator=(const Date&);
	/// предефиниран оператор >
	bool operator>(const Date& other) const;

	/// променя деня на датата
	/// @param day ден на датата
	void setDay(int day);
	/// променя месеца на датата
	/// @param month месец на датата
	void setMonth(int month);
	/// променя годината на датата
	/// @param year година на датата
	void setYear(int year);
	/// извежда датата
	void printDate() const;


	/// приятелска функция - предефиниран оператор за изход
	/// @param o поток
	/// @param d датата която се извежда
	friend std::ostream& operator<<(std::ostream& o, Date const& d);
	/// приятелска функция - предефиниран оператор за вход
	/// @param i поток
	/// @param d датата която се извежда
	friend std::istream& operator>>(std::istream& i, Date& d);
};
ostream& operator<<(ostream&, Date const&);
istream& operator>>(istream&, Date&);

#endif
