#pragma once
#include "employee.h"

class App {
  private:
    Employee *employees = nullptr;
    int size = 0;
    int capacity = 0;

    void resize();
    void showMenu() const;
    void addEmployee();
    void listEmployees() const;
    void deleteEmployee();
    void editEmployee();

    int findById(int id) const;

  public:
    App();
    App(const App &) = delete;
    App &operator=(const App &) = delete;
    ~App();

    void run();
    bool idExists(int id) const;
};
