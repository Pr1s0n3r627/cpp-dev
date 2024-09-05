#include <iostream>
#include <vector>

using namespace std;

bool isLeapYear(int year) {
if (year % 4 == 0) {
if (year % 100 == 0) {
return (year % 400 == 0);
}
return true;
}
return false;
}

int daysInMonth(int month, int year) {
vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
if (month == 2 && isLeapYear(year)) {
return 29;
}
return days[month - 1];
}

bool isValidDate(int day, int month, int year) {
if (month < 1 || month > 12) return false;
if (day < 1 || day > daysInMonth(month, year)) return false;
return true;
}

void addDays(int &day, int &month, int &year, int daysToAdd) {
day += daysToAdd;

while (day > daysInMonth(month, year)) {
day -= daysInMonth(month, year);
month++;
if (month > 12) {
month = 1;
year++;
}
}

while (day < 1) {
month--;
if (month < 1) {
month = 12;
year--;
}
day += daysInMonth(month, year);
}
}

int main() {
int day, month, year, daysToAdd;

cin >> day >> month >> year;
if (!isValidDate(day, month, year)) {
cout << "Invalid date entered!" << endl;
return 1;
}
cout << "Initial Date: " << day << "-" << month << "-" << year << endl;
cin >> daysToAdd;

addDays(day, month, year, daysToAdd);

cout << "After adding " << daysToAdd << " days: " << day << "-" << month << "-" << year << endl;
return 0;
}
