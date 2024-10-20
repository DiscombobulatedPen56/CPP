#pragma once

class Date {
	int day;
	int month;
	int year;

public:

	Date(int day, int month, int year);
	void AddDay();
	void PrintDate();
};