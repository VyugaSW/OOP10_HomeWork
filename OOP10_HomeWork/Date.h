#pragma once
#include <Windows.h>
#include <iostream>
class Date
{
	int day;
	int month;
	int year;
public:
	Date(int d, int m, int y) : day{d}, month{m}, year{y} {}
	Date() : Date(-1, -1, -1) {};

	// Function for help
	int whatDayMonth(); // Return number day of the month
	void checkMonth(); // Check number of month (if month == 12 -> month = 0, year++)

	Date operator++(){
		if (day < whatDayMonth()) {
			day++;
			if (day == whatDayMonth()) {
				month++;
				day = 0;
			}
		}
		else {
			day = 0;
			month++;
		}
		checkMonth();
	}
	Date operator--() {
		if (day < whatDayMonth()) {
			day--;
			if (day < 0) {
				month--;
				day = whatDayMonth();
			}
		}
		else {
			month--;
			day = whatDayMonth();
		}
		checkMonth();
	}
	bool operator!=(Date p) {
		if (p.day != day && p.month != month && p.year != year)
			return 1;
		return 0;
	}
	bool operator==(Date p) {
		if (p.day == day && p.month == month && p.year == year)
			return 1;
		return 0;
	}
	Date operator+=(int subDays) {
		day += subDays;
		while (day > whatDayMonth()) {
			day -= whatDayMonth();
			month++;
			checkMonth();
		}
	}
	Date operator-=(int subDays) {
		while (subDays > 0) {
			subDays -=day;
			if (subDays < 0) {
				day = abs(subDays);
				break;
			}
			month--;
			day = whatDayMonth();			
			checkMonth();
		}
	}
	Date operator=(Date p) {
		day = p.day;
		month = p.month;
		year = p.year;
	}
	bool operator>(Date p) {
		if (year > p.year)
			return 1;
		else if (year == p.year && month > p.month)
			return 1;
		else if (year == p.year && month == p.month && day > p.day)
			return 1;
		return 0;
	}
	bool operator<(Date p) {
		if (year < p.year)
			return 1;
		else if (year == p.year && month < p.month)
			return 1;
		else if (year == p.year && month == p.month && day < p.day)
			return 1;
		return 0;
	}
	Date operator()(int day, int month, int year) {
		this->day = day;
		this->month = month;
		this->year = year;
	}
	friend std::ostream& operator<<(std::ostream& output, Date& d) {
		output << d.day << "." << d.month << "." << d.year << std::endl;
		return output;
	}
	friend std::istream& operator>>(std::istream& input, Date& d) {
		input >> d.day;
		input >> d.month;
		input >> d.year;
		return input;
	}

	int getDay() {
		return day;
	}
	int getMonth() {
		return month;
	}
	int getYear() {
		return year;
	}
};

