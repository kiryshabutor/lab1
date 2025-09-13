#pragma once
#include "employee.h"

class App {
  private:
    Employee *employees = nullptr;
    int size = 0;
    int capacity = 0;

    void resize();

  public:
    App();
    ~App();

    void run();

    void showMenu() const;
    void addEmployee();
    void listEmployees() const;
    void deleteEmployee();
    void editEmployee();

    int findById(int id) const;
    bool idExists(int id) const;
};
