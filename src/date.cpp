#include "../includes/date.h"
#include "../includes/input_utils.h"
#include <array>
#include <chrono>
#include <ctime>
#include <iostream>

using namespace std;

Date::Date() : day(1), month(1), year(2000) { getCurrentDate(); }

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    getCurrentDate();
}

bool Date::isLeapYear(int y) {
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

bool Date::isValidDate(const int d,const int m,const int y) const {
    if (y < 1 || y > currentYear) {
        cout << "Invalid year\n";
        return false;
    }

    if (m < 1 || m > 12) {
        cout << "Invalid month\n";
        return false;
    }

    array<int, 12> daysInMonth = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };
    if (isLeapYear(y))
        daysInMonth[1] = 29;

    if (d < 1 || d > daysInMonth[m - 1]) {
        cout << "Invalid day for this month\n";
        return false;
    }

    if (y == currentYear && m > currentMonth ||
        (m == currentMonth && d > currentDay)) {
        cout << "Error: the entered date is in the future.\n";
        return false;
    }

    return true;
}

void Date::getCurrentDate() {
    using namespace std::chrono;

    const auto now = system_clock::now();
    time_t timeNow = system_clock::to_time_t(now);

    tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &timeNow);
#else
    localtime_r(&timeNow, &timeNow);
#endif

    currentDay = localTime.tm_mday;
    currentMonth = localTime.tm_mon + 1;
    currentYear = localTime.tm_year + 1900;
}

void Date::inputDate() {
    while (true) {
        cout << "Enter date:\n";
        const int d = safePositiveInputInt("Day: ");
        const int m = safePositiveInputInt("Month: ");
        const int y = safePositiveInputInt("Year: ");

        if (isValidDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
            break;
        } else {
            cout << "Try again.\n";
        }
    }
}

void Date::printDate() const { cout << day << "." << month << "." << year; }
