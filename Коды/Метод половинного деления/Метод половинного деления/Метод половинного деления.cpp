#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;


double f(double x)
{
    return exp(x) - exp(-x) - 2;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    double mid; //середина интервала [a,b]
    const double eps = pow(10, -6); //точность вычисления

    int cnt = 0;

    double a, b; //границы интервала, в котором содержится корень уравнения 
    double x; //корень уравнения
    cout << "Введите границы интервала [a,b] (a < b): ";
    cin >> a >> b;
    while (f(a) * f(b) > 0)
    {
        cout << "Корень не лежит на интервале [a,b]." << endl;
        cout << "Введите границы интервала [a,b] (a < b): ";
        cin >> a >> b;
    }
    while (abs(b - a) > eps)
    {
        mid = (b + a) / 2;
        cout << "x" << cnt << ": " << mid << endl;
        cnt += 1;
        if (f(mid) * f(a) > 0)
            a = mid;
        else b = mid;
    }
    x = (a + b) / 2;
    cout << "Корень уравнения x: " << x << endl;
    return 0;
}