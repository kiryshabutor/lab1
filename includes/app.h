#pragma once
#include <vector>
#include "employee.h"

class App {
private:
    std::vector<Employee> employees;

    void showMenu();
    void addEmployee();
    void listEmployees();
    int  findById(int id);
    void deleteEmployee();
    void editEmployee();

public:
    App() = default;
    ~App() = default;

    void run();
};
