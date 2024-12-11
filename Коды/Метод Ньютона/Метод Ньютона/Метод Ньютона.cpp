#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

int main()
{
    setlocale(LC_ALL, "RUS");
    const double eps = pow(10, -6); //точность вычисления

    double x0; //начальное приближенное значение корня уравнения
    double a, b; //границы интервала, в котором содержится корень уравнения 
    double x1; //следующее приближенное значение корня уравнения
    double x; //корень уравнения

    int cnt = 0;

    bool f = false;

    cout << "Введите границы интервала [a,b] (a < b): ";
    cin >> a >> b;
    cout << "Введите начальное приближенное значение корня: ";
    cin >> x0;

    while (x0 > b || x0 < a)
    {
        cout << "Начальное значение корня не входит в интервал [a,b]." << endl;
        cout << "Введите начальное значение корня: ";
        cin >> x0;
    }
    while (f != true)
    {
        x1 = x0 - (exp(x0) - exp(-x0) - 2) / ((exp(2 * x0) + 1) / (exp(x0)));//нахождение следующего значения
        if (abs(x0 - x1) < eps)//проверка на точность вычисления
        {
            x = x1;
            cout << "Корень уравнения x: " << x << endl;
            f = true;
        }
        else
        {
            x0 = x1;
            cout << "x" << cnt << ": " << x0 << endl;
            cnt += 1;
        }

    }
    return 0;
}