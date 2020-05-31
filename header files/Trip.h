#ifndef PERSONALUSERDATABASE_HEADER_INCLUDED
#define PERSONALUSERDATABASE_HEADER_INCLUDED
#include "Date.h"
#include <vector>
#include <string>
#include <fstream>
using namespace std;

const int MAX_DEST_SIZE = 20;
const int MAX_COM_SIZE = 100;
/// ������ ������ ������������, ����� ������� ���� ��������
///
/// ���� - �����:
///      - ����������
///      - ������ �� ����������
///      - ���� �� ����������
///      - ������
///      - ��������
///      - ������
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
	/// ����������� �� ������������
	Trip();
	/// ����������� � ���������
	Trip(char* destination, Date from, Date to, unsigned mark, char* comment, string image);
	/// ������� ������������ �� ����������
	/// @param destination ���������� �� ����������
	void setDestination(const char* destination);
	/// ������� ������ �� �������� �� ����������
	/// @param from ������ �� ����������
	void setFrom(Date from);
	/// ������� ������ �� ���� �� ����������
	/// @param to ���� �� ����������
	void setTo(Date to);
	/// ������� �������� �� ����������
	/// @param mark ������ �� ����������
	void setMark(unsigned mark);
	/// ������� ��������� �� ����������
	/// @param comment �������� �� ����������
	void setComment(const char* comment);
	/// ������ ������ �� ����������
	/// @param images ����� �� ������
	void setImages(vector<string> images);
	/// @returns unsigned ������
	unsigned getMark();
	/// ������ ���� ������ � ������ �� ������
	/// @param image ������
	void addImage(string image);
	/// ������� ��������
	/// @param t ��������
	/// @param destination ����������
	/// @param from ������ �� ����������
	/// @param to ���� �� ����������
	/// @param mark ������
	/// @param comment ��������
	/// @param images ������
	void createTrip(Trip& t, const char* destination, Date from, Date to, unsigned mark, const char* comment, vector<string> images);

};

#endif