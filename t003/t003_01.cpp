#include <iostream>


using namespace std;


float func1(float x)
{
    float x2, x4;
    x2 = x * x;
    x4 = x2 * x2;
    cout << "f\n";
    return x4 + 2 * x2 + 1;
}


double func1(double x) // only for C++
{
    double x2, x4;
    x2 = x * x;
    x4 = x2 * x2;
    cout << "d\n";
    return x4 + 2 * x2 + 1;
}


int main()
{
    float x, y;
    cin >> x;
    y = func1(x);
    cout << y << endl;

    double x1, y1;
    cin >> x1;
    y1 = func1(x1);
    cout << y1 << endl;
    return 0;
}
