#pragma once
#include <vector>
#include "employee.h"

class App {
private:
    std::vector<Employee> employees;

    void showMenu() const;
    void addEmployee();
    void listEmployees();
    int  findById(int id) const;
    void deleteEmployee();
    void editEmployee();

public:
    App() = default;
    ~App() = default;

    void run();
};
