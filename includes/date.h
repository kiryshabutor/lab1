#pragma once
#include <string>

class Date {
private:
    int day;
    int month;
    int year;

    int currentDay;
    int currentMonth;
    int currentYear;

    static bool isLeapYear(int y);

    bool isValidDate(int d, int m, int y) const;

    void getCurrentDate();

public:
    Date();

    Date(int d, int m, int y);

    ~Date() = default;

    void inputDate();

    void printDate() const;
};
