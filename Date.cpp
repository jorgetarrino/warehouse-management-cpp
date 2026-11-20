//
// Created by PC on 08/03/2026.
//

#include "Date.h"
#include <iostream>
using namespace std;

Date::Date() {
    day = 1;
    month = 1;
    year = 2026;
}

Date::Date(int day, int month, int year) {
    this->day = day;
    this->month = month;
    this->year = year;
}

int Date::getDay() const {
    return day;
}

int Date::getMonth() const {
    return month;
}

int Date::getYear() const {
    return year;
}

void Date::setDay(int day) {
    this->day = day;
}

void Date::setMonth(int month) {
    this->month = month;
}

void Date::setYear(int year) {
    this->year = year;
}

void Date::showDate() const {
    cout << day << "/" << month << "/" << year << endl;
}

int Date::daysDiff(const Date &other) const {
    int diff = 0;
    diff += 365 * (this->getYear() - other.getYear());
    diff += 30 * (this->getMonth() - other.getMonth());
    diff += (other.getDay() - this->getDay());
    return diff;
}