#pragma once
#include "employee.h"

class App {
private:
    Employee *employees = nullptr;
    int size = 0;
    int capacity = 0;

    void resize();

    static void showMenu();

    void addEmployee();

    void listEmployees() const;

    void deleteEmployee();

    void editEmployee() const;

    [[nodiscard]] int findById(int id) const;

public:
    App();

    App(const App &) = delete;

    App &operator=(const App &) = delete;

    ~App();

    void run();

    [[nodiscard]] bool idExists(int id) const;
};
