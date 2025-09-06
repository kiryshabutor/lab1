#include "../includes/input_utils.h"
#include <iostream>
#include <string>
#include <regex>

using namespace std;

int safeInputInt(string prompt) {
    string input;
    int number;

    regex pat(R"(^[+-]?\d+$)");

    while (true) {
        cout << prompt;
        getline(cin, input);

        while (!input.empty() && isspace((unsigned char)input.front())) input.erase(input.begin());
        while (!input.empty() && isspace((unsigned char)input.back()))  input.pop_back();

        if (!input.empty() && regex_match(input, pat)) {
            try {
                number = stoi(input);
                break;
            }
            catch (...) {
                cout << "Число вне диапазона int. Введите заново.\n";
            }
        }
        else {
            cout << "Некорректный ввод. Введите целое число (можно с + или -).\n";
        }
    }
    return number;
}

int safePositiveInputInt(string prompt) {
    int number;
    while (true) {
        number = safeInputInt(prompt);
        if (number > 0) return number;
        cout << "Число должно быть положительное\n";
    }
}

float safeInputFloat(string prompt) {
    string input;
    float number;

    regex pat(R"(^[+-]?(\d+(\.\d*)?|\.\d+)$)");

    while (true) {
        cout << prompt;
        getline(cin, input);

        while (!input.empty() && isspace((unsigned char)input.front())) input.erase(input.begin());
        while (!input.empty() && isspace((unsigned char)input.back()))  input.pop_back();

        if (!input.empty() && regex_match(input, pat)) {
            try {
                number = stof(input);
                break;
            }
            catch (...) {
                cout << "Число вне диапазона float. Введите заново.\n";
            }
        }
        else {
            cout << "Некорректный ввод. Введите вещественное число (можно с + или -).\n";
        }
    }
    return number;
}

float safePositiveInputFloat(string prompt) {
    float number;
    while (true) {
        number = safeInputFloat(prompt);
        if (number > 0) return number;
        cout << "Число должно быть положительное\n";
    }
}
