#include "Date.h"
#include <iostream>
using namespace std;

Date::Date(int day, int month, int year) : day(day), month(month), year(year)
{
}

void Date::AddDay()
{
	int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (year % 4 != 0 && (year % 100 != 0 || year % 400 == 0)) {
		days[2] = 29;
	}
	if (day < days[month]) {
		day++;
	}
	else {
		day= 1;
		if (month < 12) {
			month++;
		}
		else {
			month = 1;
			year++;
		}
	}
}

void Date::PrintDate() {
	cout << day << "." << month << "." << year;
}


