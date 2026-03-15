// That shit.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <iomanip>
#include <Windows.h>

using namespace std;

double maclaurinSin(double x, int n, double& lastTerm) {
	double sum = x; // Первый член ряда (при k=0)
	double term = x; // Текущий член ряда
    for (int k = 1; k <= n; k++) {
        term *= -x * x / ((2 * k) * (2 * k + 1));
        sum += term;
    }
    lastTerm = term; // Сохраняем последний вычисленный член
	return sum;
}
// Общая функция для вычисления любого ряда Маклорена
// Здесь нужно будет подставить ваш конкретный ряд
double maclaurinSeries(double x, int n, double& lastTerm) {
	// Пример для e^x
	return maclaurinSin(x, n, lastTerm);
}
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    double x, epsilon;
    int maxTerms;

    cout << "Вычисление значений ряда Маклорена" << endl;
    cout << "Введите значение x: ";
    cin >> x;
    cout << "Введите количество членов ряда N: ";
    cin >> maxTerms;
    cout << "Введите точность epsilon: ";
    cin >> epsilon;
    cout << "Результаты:" << endl;
    cout << "==================================================" << endl;
    cout << setw(5) << "k" << setw(15) << "Частичная сумма" << setw(15) << "Член ряда" << endl;
    cout << "--------------------------------------------------" << endl;

    double sum = 0;
    double term = 1.0;

    for (int k = 1; k <= maxTerms; k++) {
        if (k == 1) {
            // Первый член
            sum = x;
            term = x;
        }
        else {
            term *= -x * x / ((2 * (k - 1)) * (2 * (k - 1) + 1));
            sum += term;
        }
        cout << setw(5) << k << setw(15) << sum << setw(15) << term << endl;
    }

    cout << "\nПродолжение до достижения точности:" << endl;
    cout << "==================================================" << endl;
    cout << setw(5) << "k" << setw(15) << "Частичная сумма" << setw(15) << "Член ряда" << endl;
    cout << "--------------------------------------------------" << endl;

    sum = 1.0;
    term = 1.0;
    int k = 0;

    cout << setw(5) << k << setw(15) << sum << setw(15) << term << endl;

    do {
        k++;
        term *= x / k;
        sum += term;

        cout << setw(5) << k << setw(15) << sum
            << setw(15) << term << endl;

    } while (abs(term) > epsilon && k < maxTerms * 2);

    cout << "--------------------------------------------------" << endl;
    cout << "Достигнутая точность: " << abs(term) << endl;
    cout << "Точное значение (cmath): " << sin(x) << endl;
    cout << "Абсолютная погрешность: " << abs(sin(x) - sum) << endl;
    cout << "Относительная погрешность: " << abs((sin(x) - sum) / sin(x)) * 100 << "%" << endl;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
