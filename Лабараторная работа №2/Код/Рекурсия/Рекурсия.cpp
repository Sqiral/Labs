#include <iostream>
#include <clocale>
#include <cmath>

using namespace std;

double f(int n, double x);
double g(int n);
double get_sum(int n, double x);

int main()
{
    int n;
    double x;
    setlocale(LC_ALL, "RUS");
    cout << "Введите значение x: ";
    cin >> x;
    cout << "Введите кол-во членов ряда: ";
    cin >> n;
    while (n <= 0)
    {
        cout << "Кол-во членов должно быть натуральным числом,\
введите значение еще раз!\n\
Введите кол-во членов ряда: ";
        cin >> n;
    }
    double s = get_sum(n, x);
    cout << "Сумма членов ряда S равна:" << s;
    return 0;
}

double f(int n, double x)
{
    if (n == 1)
        return pow(1 + x, 2);
    return pow(x + 1, 2 * n);
}

double g(int n)
{
    if (n == 1)
        return -1;
    return pow(-1, n);
}

double get_sum(int n, double x)
{
    if (n == 1)
        return (g(n) * (f(n, x))) / (n);
    return (g(n) * (f(n, x))) / (n)+get_sum(n - 1, x);
}




