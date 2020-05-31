#ifndef PERSONALUSERDATABASE_HEADER_INCLUDED
#define PERSONALUSERDATABASE_HEADER_INCLUDED
#include "Date.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const int MAX_DEST_SIZE = 20;
const int MAX_COM_SIZE = 100;
/// класът описва информацията, която съдържа едно пътуване
///
/// член - данни:
///		 - дестинация
///		 - начало на пътуването
///		 - край на пътуването
///		 - оценка
///		 - коментар
///	     - снимки
class Trip
{
private:

	char destination[MAX_DEST_SIZE];
	Date from;
	Date to;
	unsigned mark;
	char comment[MAX_COM_SIZE];
	vector<string> images;
public:
	/// конструктор по подразбиране
	Trip();
	/// конструктор с параметри
	Trip(char* destination, Date from, Date to, unsigned mark, char* comment, string image);
	/// променя дестинацията на пътуването
	/// @param destination дестинация на пътуването
	void setDestination(const char* destination);
	/// променя датата на началото на пътуването
	/// @param from начало на пътуването
	void setFrom(Date from);
	/// променя датата на край на пътуването
	/// @param to край на пътуването
	void setTo(Date to);
	/// променя оценката на пътуването
	/// @param mark оценка на пътуването
	void setMark(unsigned mark);
	/// променя коментара на пътуването
	/// @param comment коментар на пътуването
	void setComment(const char* comment);
	/// добавя снимки на пътуването
	/// @param images масив от снимки
	void setImages(vector<string> images);
	/// @returns unsigned оценка
	unsigned getMark();
	/// добавя една снимка в масива от снимки
	/// @param image снимка
	void addImage(string image);
	/// създава пътуване
	/// @param t пътуване
	/// @param destination дестинация
	/// @param from начало на пътуването
	/// @param to край на пътуването
	/// @param mark оценка
	/// @param comment коментар
	/// @param images снимки
	void createTrip(Trip& t, const char* destination, Date from, Date to, unsigned mark, const char* comment, vector<string> images);

};

#endif
