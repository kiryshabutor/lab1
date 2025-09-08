#pragma once
#include "date.h"
#include <string>

enum class EmployeeType {
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
    Employee() = default;
    Employee(int id, float s, Date d, EmployeeType t);
    ~Employee() = default;

    void getEmploy();
    void putEmploy() const;
    void edit();
    int getId() const;
};
