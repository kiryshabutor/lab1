#pragma once
#include "date.h"
#include <string>

enum EmployeeType {
    LABORANT = 1,
    SECRETARY,
    MANAGER,
    ENGINEER,
    DIRECTOR
};

std::string employeeTypeToString(EmployeeType type);

class Employee {
private:
    int employeeId;
    float salary;
    Date hireDate;
    EmployeeType type;

public:
    Employee();
    Employee(int id, float s, Date d, EmployeeType t);
    ~Employee();

    void getEmploy();
    void putEmploy();
    void edit();
    int getId();
};
