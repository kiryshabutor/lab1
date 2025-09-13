#include "../includes/input_utils.h"

#include <algorithm>
#include <iostream>
#include <regex>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

inline void trim_inplace(string &s) {
    while (!s.empty() && isspace(static_cast<unsigned char>(s.front())))
        s.erase(s.begin());
    while (!s.empty() && isspace(static_cast<unsigned char>(s.back())))
        s.pop_back();
}

string readLineTrimmed(const string &prompt) {
    string input;
    cout << prompt;
    getline(cin, input);
    trim_inplace(input);
    return input;
}

int safeInputInt(const string &prompt) {
    regex pat(R"(^[+-]?\d+$)");

    while (true) {
        string input = readLineTrimmed(prompt);

        if (!input.empty() && regex_match(input, pat)) {
            try {
                return stoi(input);
            } catch (const invalid_argument &) {
                cout << "Невалидный ввод. Введите число.\n";
            } catch (const out_of_range &) {
                cout << "Число вне диапазона int. Введите заново.\n";
            }
        } else {
            cout << "Некорректный ввод. Введите целое число (можно с + или "
                    "-).\n";
        }
    }
}

int safePositiveInputInt(const string &prompt) {
    while (true) {
        if (int number = safeInputInt(prompt); number > 0)
            return number;
        cout << "Число должно быть положительное\n";
    }
}

float safeInputFloat(const string &prompt) {
    static const regex pat(R"(^[+-]?\d+([.,]\d{0,2})?$)");

    while (true) {
        string input = readLineTrimmed(prompt);

        if (!input.empty() && regex_match(input, pat)) {
            replace(input.begin(), input.end(), ',', '.');

            stringstream ss(input);
            ss.imbue(locale::classic());
            float value;
            ss >> value;

            if (ss && ss.eof()) {
                return value;
            } else {
                cout << "Невалидный ввод. Введите число.\n";
            }
        } else {
            cout << "Некорректный ввод.\n";
        }
    }
}

float safePositiveInputFloat(const string &prompt) {
    while (true) {
        float number = safeInputFloat(prompt);
        if (number > 0.0f)
            return number;
        cout << "Число должно быть положительное\n";
    }
}
