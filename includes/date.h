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

    bool isLeapYear(int y);
    bool isValidDate(int d, int m, int y);
    void getCurrentDate();
    int safeInputData(std::string prompt);

public:
    Date();
    Date(int d, int m, int y);
    ~Date();

    void inputDate();
    void printDate();
};
