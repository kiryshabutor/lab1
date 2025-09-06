#include "../includes/app.h"
#include "../includes/input_utils.h"
#include <iostream>
using namespace std;

App::App() {}

App::~App() {}

void App::showMenu() {
    cout << "\n==== МЕНЮ ====\n";
    cout << "1. Добавить сотрудника\n";
    cout << "2. Удалить сотрудника\n";
    cout << "3. Вывести всех сотрудников\n";
    cout << "4. Изменить данные сотрудника\n";
    cout << "5. Выход\n";
}

void App::addEmployee() {
    Employee e;
    cout << "\n--- Добавление сотрудника ---\n";
    e.getEmploy();
    employees.push_back(e);
    cout << "Сотрудник добавлен.\n";
}

void App::listEmployees() {
    if (employees.empty()) {
        cout << "Список пуст.\n";
        return;
    }
    cout << "\n===== Список сотрудников =====\n";
    for (int i = 0; i < (int)employees.size(); i++) {
        cout << "\n#" << (i + 1) << "\n";
        employees[i].putEmploy();
    }
}

int App::findById(int id) {
    for (int i = 0; i < (int)employees.size(); i++) {
        if (employees[i].getId() == id) return i;
    }
    return -1;
}

void App::deleteEmployee() {
    if (employees.empty()) {
        cout << "Удалять нечего, список пуст.\n";
        return;
    }
    int id = safePositiveInputInt("Введите ID сотрудника для удаления: ");
    int idx = findById(id);
    if (idx == -1) {
        cout << "Сотрудник с таким ID не найден.\n";
        return;
    }
    employees.erase(employees.begin() + idx);
    cout << "Сотрудник удалён.\n";
}

void App::editEmployee() {
    if (employees.empty()) {
        cout << "Редактировать нечего, список пуст.\n";
        return;
    }
    int id = safePositiveInputInt("Введите ID сотрудника для редактирования: ");
    int idx = findById(id);
    if (idx == -1) {
        cout << "Сотрудник с таким ID не найден.\n";
        return;
    }
    employees[idx].edit();
}

void App::run() {
    setlocale(LC_ALL, "");

    while (true) {
        showMenu();
        int choice = safeInputInt("Выбор: ");
        switch (choice) {
        case 1: addEmployee();    break;
        case 2: deleteEmployee();  break;
        case 3: listEmployees();   break;
        case 4: editEmployee();    break;
        case 5:
            cout << "Выход.\n";
            return;
        default:
            cout << "Некорректный пункт меню.\n";
        }
    }
}
