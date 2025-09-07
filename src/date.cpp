#include "../includes/date.h"
#include "../includes/input_utils.h"
#include <iostream>
#include <chrono>
#include <ctime>

using namespace std;

Date::Date() : day(1), month(1), year(2000) {
    getCurrentDate();
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y) {
    getCurrentDate();
}

bool Date::isLeapYear(int y) const{
    return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
}

bool Date::isValidDate(int d, int m, int y) const{
    if (y < 1 || y > currentYear) {
        cout << "Некорректный год\n";
        return false;
    }

    if (m < 1 || m > 12) {
        cout << "Нет такого месяца\n";
        return false;
    }

    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (isLeapYear(y)) daysInMonth[1] = 29;

    if (d < 1 || d > daysInMonth[m - 1]) {
        cout << "В этом месяце нет такого дня\n";
        return false;
    }

    if (y == currentYear && m > currentMonth || (m == currentMonth && d > currentDay)) {
        cout << "Ошибка: введенная дата находится в будущем.\n";
        return false;
    }

    return true;
}

void Date::getCurrentDate() {
    using namespace std::chrono;

    auto now = system_clock::now();
    time_t timeNow = system_clock::to_time_t(now);

    tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &timeNow);
#else
    localtime_r(&timeNow, &localTime);
#endif

    currentDay = localTime.tm_mday;
    currentMonth = localTime.tm_mon + 1;
    currentYear = localTime.tm_year + 1900;
}

void Date::inputDate() {
    int d, m, y;
    while (true) {
        cout << "Введите дату:\n";
        d = safePositiveInputInt("День: ");
        m = safePositiveInputInt("Месяц: ");
        y = safePositiveInputInt("Год: ");

        if (isValidDate(d, m, y)) {
            day = d;
            month = m;
            year = y;
            break;
        }
        else {
            cout << "Попробуйте снова.\n";
        }
    }
}

void Date::printDate() const {
    cout << day << "." << month << "." << year;
}
