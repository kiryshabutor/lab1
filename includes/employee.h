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

class App;

class Employee {
private:
    int employeeId{};
    float salary{};
    Date hireDate{};
    EmployeeType type{EmployeeType::LABORANT};

public:
    Employee() = default;

    Employee(int id, float s, Date d, EmployeeType t);

    void getEmployDataWithoutId();

    void putEmploy() const;

    void edit(const App &app);

    int getId() const;

    void setId(int id);
};
