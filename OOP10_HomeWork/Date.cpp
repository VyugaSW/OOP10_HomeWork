#include "Date.h"
#include <Windows.h>
#include <iostream>
//Helping functions
int Date::whatDayMonth() {
	switch (month) {
	case 1:
	case 3:
	case 5:
	case 7:
	case 8:
	case 10:
	case 12:
		return 31;
		break;
	case 4:
	case 6:
	case 9:
	case 11:
		return 30;
		break;
	case 2:
		if (year % 4 == 0 && year % 100 != 0)
			return 29;
		else if (year % 100 == 0 && year % 400 == 0)
			return 29;
		else
			return 28;
	}
}
void Date::checkMonth() {
	if (month == 12) {
		year++;
		month = 0;
	}
	else if (month == 0) {
		year--;
		month = 12;
	}
}