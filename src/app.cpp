#include "../includes/app.h"
#include "../includes/input_utils.h"
#include <iostream>

using namespace std;

App::App() = default;

App::~App() { delete[] employees; }

void App::resize() {
    const int newCapacity = (capacity == 0) ? 2 : capacity * 2;
    const auto newArr = new Employee[newCapacity];
    const int limit = (size < newCapacity) ? size : newCapacity;
    for (int i = 0; i < limit; ++i)
        newArr[i] = employees[i];
    delete[] employees;
    employees = newArr;
    capacity = newCapacity;
}

void App::showMenu(){
    cout << "\n==== MENU ====\n";
    cout << "1. Add employee\n";
    cout << "2. Delete employee\n";
    cout << "3. Show all employees\n";
    cout << "4. Edit employee data\n";
    cout << "5. Exit\n";
}

bool App::idExists(const int id) const { return findById(id) != -1; }

void App::addEmployee() {
    Employee e;
    cout << "\n--- Adding employee ---\n";

    int id;
    while (true) {
        id = safePositiveInputInt("Enter employee ID: ");
        if (!idExists(id))
            break;
        cout << "Error: ID " << id << " already exists. Enter another one.\n";
    }
    e.setId(id);
    e.getEmployDataWithoutId();

    while (size >= capacity)
        resize();
    ++size;
    employees[size - 1] = e;
    cout << "Employee added.\n";
}

void App::listEmployees() const {
    if (size == 0) {
        cout << "Employee list is empty.\n";
        return;
    }
    cout << "\n===== Employee list =====\n";
    for (int i = 0; i < size; ++i) {
        cout << "\n#" << (i + 1) << "\n";
        employees[i].putEmploy();
    }
}

int App::findById(const int id) const {
    for (int i = 0; i < size; ++i) {
        if (employees[i].getId() == id)
            return i;
    }
    return -1;
}

void App::deleteEmployee() {
    if (size == 0) {
        cout << "Nothing to delete, employee list is empty.\n";
        return;
    }
    int id = safePositiveInputInt("Enter employee ID to delete: ");
    int idx = findById(id);
    if (idx == -1) {
        cout << "Employee with this ID not found.\n";
        return;
    }
    for (int i = idx; i < size - 1; ++i)
        employees[i] = employees[i + 1];
    --size;
    cout << "Employee deleted.\n";
}

void App::editEmployee() const{
    if (size == 0) {
        cout << "Nothing to edit, employee list is empty.\n";
        return;
    }
    const int id = safePositiveInputInt("Enter employee ID to edit: ");
    const int idx = findById(id);
    if (idx == -1) {
        cout << "Employee with this ID not found.\n";
        return;
    }
    employees[idx].edit(*this);
}

void App::run() {
    while (true) {
        showMenu();
        switch (safeInputInt("Your choice: ")) {
            case 1:
                addEmployee();
                break;
            case 2:
                deleteEmployee();
                break;
            case 3:
                listEmployees();
                break;
            case 4:
                editEmployee();
                break;
            case 5:
                cout << "Exiting.\n";
                return;
            default:
                cout << "Invalid menu option.\n";
        }
    }
}
