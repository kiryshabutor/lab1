#pragma once
#include "employee.h"

class App {
private:
    Employee* employees;
    int size;
    int capacity;

    void resize();
    void showMenu() const;
    void addEmployee();
    void listEmployees() const;
    int  findById(int id) const;
    void deleteEmployee();
    void editEmployee();

    App(const App&) = delete;
    App& operator=(const App&) = delete;

public:
    App();
    ~App();

    void run();
};

