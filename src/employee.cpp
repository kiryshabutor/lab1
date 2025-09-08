#include "../includes/employee.h"
#include "../includes/input_utils.h"
#include <iostream>

using namespace std;
using enum EmployeeType;

Employee::Employee(int id, float s, Date d, EmployeeType t)
    : employeeId(id), salary(s), hireDate(d), type(t) {}

string employeeTypeToString(EmployeeType type) {
    using enum EmployeeType;
    switch (type) {
    case LABORANT:
        return "Лаборант";
    case SECRETARY:
        return "Секретарь";
    case MANAGER:
        return "Менеджер";
    case ENGINEER:
        return "Инженер";
    case DIRECTOR:
        return "Директор";
    default:
        return "Неизвестно";
    }
}

void Employee::getEmploy() {
    employeeId = safePositiveInputInt("Введите номер сотрудника: ");
    salary = safePositiveInputFloat("Введите оклад сотрудника: ");
    hireDate.inputDate();

    int typeChoice = safeInputInt(
        "Выберите должность сотрудника:\n"
        "1 - Лаборант\n2 - Секретарь\n3 - Менеджер\n4 - Инженер\n5 - Директор\n"
        "Выбор: ");

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
    cout << "Номер: " << employeeId << "\n";
    cout << "Оклад: " << salary << "\n";
    cout << "Дата приема: ";
    hireDate.printDate();
    cout << "\nДолжность: " << employeeTypeToString(type) << "\n";
}

int Employee::getId() const { return employeeId; }

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
        switch (safeInputInt("Новая должность:\n"
                             "1 - Лаборант\n2 - Секретарь\n3 - Менеджер\n4 - "
                             "Инженер\n5 - Директор\n"
                             "Выбор: ")) {
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
            cout << "Некорректный выбор. Должность не изменена.\n";
            break;
        }
        cout << "Готово.\n";
        break;
    }
    default:
        cout << "Отмена.\n";
        break;
    }
}
