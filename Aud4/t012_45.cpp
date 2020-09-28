#include <iostream>


using namespace std;


double func1_sin(double x, double eps)
{
    int k = 3;
    double a1 = x, a2 = - x*x*x / 6, a3, s = x;
    while (abs(a2 - a1) > eps)
    {
        a3 = - x*x * a2 / ((2*k - 2) * (2*k - 1));
        a1 = a2;
        a2 = a3;
        s += a1;
        k++;
    }
    return s;
}


int main()
{
    double x, eps;
    cin >> x >> eps;
    cout << func1_sin(x, eps) << endl;
    return 0;
}
