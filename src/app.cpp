#include "../includes/app.h"
#include "../includes/input_utils.h"
#include <iostream>

using namespace std;

App::App() = default;

App::~App() { delete[] employees; }

void App::resize() {
    int newCapacity = (capacity == 0) ? 2 : capacity * 2;
    auto newArr = new Employee[newCapacity];
    int limit = (size < newCapacity) ? size : newCapacity;
    for (int i = 0; i < limit; ++i)
        newArr[i] = employees[i];
    delete[] employees;
    employees = newArr;
    capacity = newCapacity;
}

void App::showMenu() const {
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
    while (size >= capacity)
        resize();
    employees[size] = e;
    ++size;
    cout << "Сотрудник добавлен.\n";
}

void App::listEmployees() const {
    if (size == 0) {
        cout << "Список пуст.\n";
        return;
    }
    cout << "\n===== Список сотрудников =====\n";
    for (int i = 0; i < size; ++i) {
        cout << "\n#" << (i + 1) << "\n";
        employees[i].putEmploy();
    }
}

int App::findById(int id) const {
    for (int i = 0; i < size; ++i) {
        if (employees[i].getId() == id)
            return i;
    }
    return -1;
}

void App::deleteEmployee() {
    if (size == 0) {
        cout << "Удалять нечего, список пуст.\n";
        return;
    }
    int id = safePositiveInputInt("Введите ID сотрудника для удаления: ");
    int idx = findById(id);
    if (idx == -1) {
        cout << "Сотрудник с таким ID не найден.\n";
        return;
    }
    for (int i = idx; i < size - 1; ++i)
        employees[i] = employees[i + 1];
    --size;
    cout << "Сотрудник удалён.\n";
}

void App::editEmployee() {
    if (size == 0) {
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
    while (true) {
        showMenu();
        int choice = safeInputInt("Выбор: ");
        switch (choice) {
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
            cout << "Выход.\n";
            return;
        default:
            cout << "Некорректный пункт меню.\n";
        }
    }
}
