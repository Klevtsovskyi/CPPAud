#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    int a = 14;
    double x = 123.456;
    double y = 0.0031;
    double z = 90.9;

    cout << setprecision(2);
    cout << fixed;
    cout << showpos;
    cout << hex << uppercase << showbase;
    cout << setfill(',');
    cout << internal;

    cout << setw(10) << a << ends;
    cout << setw(10) << x << ends;
    cout << setw(10) << y << ends;
    cout << setw(10) << z << ends;
    return 0;
}
