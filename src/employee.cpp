#include "../includes/employee.h"
#include "../includes/input_utils.h"
#include <iostream>

using namespace std;

Employee::Employee(int id, float s, Date d, EmployeeType t)
    : employeeId(id), salary(s), hireDate(d), type(t) {}

string employeeTypeToString(EmployeeType type) {
    switch (type) {
    case EmployeeType::LABORANT:  return "Лаборант";
    case EmployeeType::SECRETARY: return "Секретарь";
    case EmployeeType::MANAGER:   return "Менеджер";
    case EmployeeType::ENGINEER:  return "Инженер";
    case EmployeeType::DIRECTOR:  return "Директор";
    default:                      return "Неизвестно";
    }
}

void Employee::getEmploy() {
    employeeId = safePositiveInputInt("Введите номер сотрудника: ");
    salary = safePositiveInputFloat("Введите оклад сотрудника: ");
    hireDate.inputDate();

    int typeChoice = safeInputInt(
        "Выберите должность сотрудника:\n"
        "1 - Лаборант\n2 - Секретарь\n3 - Менеджер\n4 - Инженер\n5 - Директор\n"
        "Выбор: "
    );

    switch (typeChoice) {
    case 1: type = EmployeeType::LABORANT; break;
    case 2: type = EmployeeType::SECRETARY; break;
    case 3: type = EmployeeType::MANAGER; break;
    case 4: type = EmployeeType::ENGINEER; break;
    case 5: type = EmployeeType::DIRECTOR; break;
    default: type = EmployeeType::LABORANT; break;
    }
}

void Employee::putEmploy() const {
    cout << "Номер: " << employeeId << "\n";
    cout << "Оклад: " << salary << "\n";
    cout << "Дата приема: ";
    hireDate.printDate();
    cout << "\nДолжность: " << employeeTypeToString(type) << "\n";
}

int Employee::getId() const {
    return employeeId;
}

void Employee::edit() {
    cout << "\nРедактирование сотрудника (ID: " << employeeId << ")\n";
    cout << "1. Изменить номер\n";
    cout << "2. Изменить оклад\n";
    cout << "3. Изменить дату приема\n";
    cout << "4. Изменить должность\n";
    cout << "5. Отмена\n";
    int choice = safeInputInt("Выбор: ");
    switch (choice) {
    case 1:
        employeeId = safePositiveInputInt("Новый номер: ");
        cout << "Готово.\n";
        break;
    case 2:
        salary = safePositiveInputFloat("Новый оклад: ");
        cout << "Готово.\n";
        break;
    case 3:
        cout << "Новая дата:\n";
        hireDate.inputDate();
        cout << "Готово.\n";
        break;
    case 4: {
        int t = safeInputInt(
            "Новая должность:\n"
            "1 - Лаборант\n2 - Секретарь\n3 - Менеджер\n4 - Инженер\n5 - Директор\n"
            "Выбор: "
        );
        switch (t) {
        case 1: type = EmployeeType::LABORANT; break;
        case 2: type = EmployeeType::SECRETARY; break;
        case 3: type = EmployeeType::MANAGER; break;
        case 4: type = EmployeeType::ENGINEER; break;
        case 5: type = EmployeeType::DIRECTOR; break;
        default: cout << "Некорректный выбор. Должность не изменена.\n"; break;
        }
        cout << "Готово.\n";
        break;
    }
    default:
        cout << "Отмена.\n";
        break;
    }
}
