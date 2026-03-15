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
void testMaclaurinSin() {
    cout << "===== ТЕСТИРОВАНИЕ ФУНКЦИИ maclaurinSin =====" << endl;

    // Тест 1: Проверка при x = 0
    cout << "\nТест 1: x = 0" << endl;
    double lastTerm;
    double result = maclaurinSin(0, 5, lastTerm);
    cout << "Ожидаемое значение: 0.0" << endl;
    cout << "Полученное значение: " << result << endl;
    cout << "Последний член: " << lastTerm << endl;
    cout << (abs(result - 0.0) < 1e-10 ? "✓ ТЕСТ ПРОЙДЕН" : "✗ ТЕСТ НЕ ПРОЙДЕН") << endl;

    // Тест 2: Проверка при x = 1 (sin(1) ≈ 0.841471)
    cout << "\nТест 2: x = 1, n = 10" << endl;
    result = maclaurinSin(1, 10, lastTerm);
    double expected = sin(1.0);
    cout << "Ожидаемое значение (приблизительно): " << expected << endl;
    cout << "Полученное значение: " << result << endl;
    cout << "Погрешность: " << abs(expected - result) << endl;
    cout << (abs(expected - result) < 1e-7 ? "✓ ТЕСТ ПРОЙДЕН" : "✗ ТЕСТ НЕ ПРОЙДЕН") << endl;

    // Тест 3: Проверка при x = π/2 (sin(π/2) = 1)
    cout << "\nТест 3: x = π/2, n = 15" << endl;
    double pi = 3.141592653589793;
    result = maclaurinSin(pi / 2, 15, lastTerm);
    expected = sin(pi / 2);
    cout << "Ожидаемое значение (приблизительно): " << expected << endl;
    cout << "Полученное значение: " << result << endl;
    cout << "Погрешность: " << abs(expected - result) << endl;
    cout << (abs(expected - result) < 1e-7 ? "✓ ТЕСТ ПРОЙДЕН" : "✗ ТЕСТ НЕ ПРОЙДЕН") << endl;

    // Тест 4: Проверка при отрицательном x
    cout << "\nТест 4: x = -1, n = 15" << endl;
    result = maclaurinSin(-1, 15, lastTerm);
    expected = sin(-1.0);
    cout << "Ожидаемое значение (приблизительно): " << expected << endl;
    cout << "Полученное значение: " << result << endl;
    cout << "Погрешность: " << abs(expected - result) << endl;
    cout << (abs(expected - result) < 1e-7 ? "✓ ТЕСТ ПРОЙДЕН" : "✗ ТЕСТ НЕ ПРОЙДЕН") << endl;

    // Тест 5: Проверка для малого n
    cout << "\nТест 5: x = 1, n = 2 (должно быть 1 - 1/6 = 0.833333)" << endl;
    result = maclaurinSin(1, 2, lastTerm);
    cout << "Ожидаемое значение: 0.833333" << endl;
    cout << "Полученное значение: " << result << endl;
    cout << (abs(result - 0.833333) < 1e-5 ? "✓ ТЕСТ ПРОЙДЕН" : "✗ ТЕСТ НЕ ПРОЙДЕН") << endl;

    cout << "\n===== ТЕСТИРОВАНИЕ ЗАВЕРШЕНО =====" << endl;
}
// Функция для автоматического тестирования с разными параметрами
void autoTest() {
    cout << "\n===== АВТОМАТИЧЕСКОЕ ТЕСТИРОВАНИЕ =====" << endl;

    double testValues[] = { 0, 0.5, 1, 2, -0.5, -1 };
    int ns[] = { 5, 10, 15 };

    cout << setw(5) << "x" << setw(8) << "n" << setw(15) << "Результат"
        << setw(15) << "sin(x)" << setw(15) << "Погрешность" << endl;
    cout << "--------------------------------------------------------" << endl;

    for (double x : testValues) {
        for (int n : ns) {
            double lastTerm;
            double result = maclaurinSin(x, n, lastTerm);
            double exact = sin(x);
            double error = abs(exact - result);

            cout << setw(5) << x << setw(8) << n << setw(15) << result
                << setw(15) << exact << setw(15) << error << endl;
        }
    }
}
// Простая функция для проверки конкретного случая
void checkCase(double x, int n) {
    double lastTerm;
    double result = maclaurinSin(x, n, lastTerm);
    double exact = sin(x);

    cout << "\nПроверка: x = " << x << ", n = " << n << endl;
    cout << "Результат: " << result << endl;
    cout << "Точное значение: " << exact << endl;
    cout << "Погрешность: " << abs(exact - result) << endl;
    cout << "Последний член: " << lastTerm << endl;
}
int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    testMaclaurinSin();
    autoTest();

    cout << "\nПроверка конкретных случаев:" << endl;
    checkCase(1.5, 8);
    checkCase(-0.5, 10);

    double x, epsilon;
    int maxTerms;

    cout << "\n\nВычисление значений ряда Маклорена" << endl;
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
