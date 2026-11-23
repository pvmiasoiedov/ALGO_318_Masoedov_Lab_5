#include <iostream>
#include <cmath>

using namespace std;

// Прості функції перевірки вводу (Завдання 4)
int inputInt(int minVal, int maxVal) {
    int val;
    cin >> val;
    while (val < minVal || val > maxVal) {
        cout << "Помилка! Введіть число від " << minVal << " до " << maxVal << ": ";
        cin >> val;
    }
    return val;
}

double inputDouble(double minVal, double maxVal) {
    double val;
    cin >> val;
    while (val < minVal || val > maxVal) {
        cout << "Помилка! Введіть число від " << minVal << " до " << maxVal << ": ";
        cin >> val;
    }
    return val;
}

// Завдання 1 (Варіант 7 - зелений колір)
void task1() {
    cout << "Введіть кількість точок n: ";
    int n = inputInt(1, 1000);

    cout << "Введіть сторону квадрата a (a > 0): ";
    double a = inputDouble(0.001, 10000);

    double r = a / 2.0;
    int count = 0;

    for (int i = 1; i <= n; i++) {
        double x, y;
        cout << "Точка " << i << " (введіть x та y через пробіл): ";
        cin >> x >> y;

        // Перевірка, чи точка всередині кола
        bool inCircle = (x * x + (y + r) * (y + r)) <= (r * r);

        // Перевірка 3-х зелених частин фігури
        bool part1 = (x >= -r && x <= 0) && (y >= 0 && y <= x + r);
        bool part2 = (x >= -r && x <= 0) && (y >= -a && y <= x - r) && !inCircle;
        bool part3 = (x >= 0 && x <= r) && (y >= -a && y <= -r) && !inCircle;

        if (part1 || part2 || part3) {
            count++;
        }
    }
    cout << "Кількість точок у фігурі: " << count << endl;
}

// Завдання 2 (Варіант 7 -> непарний: кожен 4-й елемент; формула з табл. 2, вар. 10)
void task2() {
    cout << "Введіть x (|x| < 4): ";
    double x = inputDouble(-3.99, 3.99);

    cout << "Введіть натуральне n (n >= 1): ";
    int n = inputInt(1, 100);

    double sum = 0, xs;
    for (int i = 0; i <= n; i++) {
        xs = pow(x, i + 2) / (pow(5.0, i) + i);
        sum += xs;

        // Виводимо кожен 4-й елемент
        if ((i + 1) % 4 == 0) {
            cout << "Елемент №" << (i + 1) << ": " << xs << endl;
        }
    }
    cout << "Сума: " << sum << endl;
}

// Завдання 3 (Варіант 14: дослідження ряду на збіжність)
void task3() {
    double x, u, sum;
    double e = 1E-10;
    double g = 1E+4;

    cout << "Введіть x: ";
    cin >> x;

    int n = 1;
    double fact = 1.0;
    u = (pow(x, 2) + pow(1.0, x)) / fact; // 1-й елемент
    sum = 0;

    while (fabs(u) >= e && fabs(u) <= g) {
        cout << "n = " << n << ", u = " << u << endl;
        sum += u;

        n++;
        fact = fact * n; // рахуємо факторіал n!
        u = (pow(x, 2 * n) + pow(n, x)) / fact;
    }

    cout << "Останній елемент u = " << u << endl;
    if (fabs(u) < e) {
        cout << "Ряд збіжний. Сума: " << sum << endl;
    } else {
        cout << "Ряд розбіжний." << endl;
    }
}

// Головна функція з меню
int main() {
    setlocale(LC_ALL, "Ukrainian");
    int menu;
    do {
        cout << "\n--- МЕНЮ ---\n";
        cout << "1 - Завдання 1\n";
        cout << "2 - Завдання 2\n";
        cout << "3 - Завдання 3\n";
        cout << "0 - Вихід\n";
        cout << "Ваш вибір: ";
        cin >> menu;

        switch (menu) {
            case 1: task1(); break;
            case 2: task2(); break;
            case 3: task3(); break;
            case 0: cout << "Exit ..." << endl; break;
            default: cout << "Wrong task!" << endl;
        }
    } while (menu != 0);

    return 0;
}