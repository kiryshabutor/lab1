#include "../includes/employee.h"
#include "../includes/app.h"
#include "../includes/input_utils.h"
#include <iomanip>
#include <iostream>

using namespace std;
using enum EmployeeType;

Employee::Employee(const int id, const float s, const Date& d, const EmployeeType t)
    : employeeId(id), salary(s), hireDate(d), type(t) {
}

string employeeTypeToString(EmployeeType type) {
    using enum EmployeeType;
    switch (type) {
        case LABORANT:
            return "Lab Assistant";
        case SECRETARY:
            return "Secretary";
        case MANAGER:
            return "Manager";
        case ENGINEER:
            return "Engineer";
        case DIRECTOR:
            return "Director";
        default:
            return "Unknown";
    }
}

void Employee::getEmployDataWithoutId() {
    salary = safePositiveInputFloat("Enter employee salary: ");
    hireDate.inputDate();

    int typeChoice = safeInputInt(
        "Choose employee position:\n"
        "1 - Lab Assistant\n2 - Secretary\n3 - Manager\n4 - Engineer\n5 - Director\n"
        "Choice: ");

    switch (typeChoice) {
        case 1:
            type = LABORANT;
            break;
        case 2:
            type = SECRETARY;
            break;
        case 3:
            type = MANAGER;
            break;
        case 4:
            type = ENGINEER;
            break;
        case 5:
            type = DIRECTOR;
            break;
        default:
            type = LABORANT;
            break;
    }
}

void Employee::putEmploy() const {
    cout << "ID: " << employeeId << "\n";
    cout << fixed << setprecision(2);
    cout << "Salary: " << salary << "\n";
    cout << "Hire date: ";
    hireDate.printDate();
    cout << "\nPosition: " << employeeTypeToString(type) << "\n";
}

int Employee::getId() const { return employeeId; }

void Employee::setId(const int id) { employeeId = id; }

void Employee::edit(const App &app) {
    cout << "\nEditing employee (ID: " << employeeId << ")\n";
    cout << "1. Change ID\n";
    cout << "2. Change salary\n";
    cout << "3. Change hire date\n";
    cout << "4. Change position\n";
    cout << "5. Cancel\n";
    switch (safeInputInt("Choice: ")) {
        case 1: {
            int newId;
            while (true) {
                newId = safePositiveInputInt("New ID: ");
                if (newId == employeeId || !app.idExists(newId))
                    break;
                cout << "Error: ID " << newId << " is already taken. Enter another.\n";
            }
            employeeId = newId;
            cout << "Done.\n";
            break;
        }
        case 2:
            salary = safePositiveInputFloat("New salary: ");
            cout << "Done.\n";
            break;
        case 3:
            cout << "New date:\n";
            hireDate.inputDate();
            cout << "Done.\n";
            break;
        case 4: {
            switch (safeInputInt("New position:\n"
                "1 - Lab Assistant\n2 - Secretary\n3 - Manager\n4 - Engineer\n5 - Director\n"
                "Choice: ")) {
                case 1:
                    type = LABORANT;
                    break;
                case 2:
                    type = SECRETARY;
                    break;
                case 3:
                    type = MANAGER;
                    break;
                case 4:
                    type = ENGINEER;
                    break;
                case 5:
                    type = DIRECTOR;
                    break;
                default:
                    cout << "Invalid choice. Position not changed.\n";
                    break;
            }
            cout << "Done.\n";
            break;
        }
        default:
            cout << "Cancelled.\n";
            break;
    }
}
