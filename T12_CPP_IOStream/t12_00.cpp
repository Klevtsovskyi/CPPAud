#include <iostream>
#include <iomanip>
#include <ios>
#include <cstdio>
#include <cstdlib>
using namespace std;


int main() {
    system("color F0");
    double x = 123.56789;
    cout << fixed << setprecision(2) << setw(10);
    cout << setfill('~') << left;
    // cout.width(15);  // same as << setw(15);
    cout << x << endl;
    cout << defaultfloat << setprecision(-1) << x << endl;

    bool b = true;
    cout << b << endl;
    cout << boolalpha << b << endl;
    cout << noboolalpha << b << endl;

    int n = 10;
    int* arr = new int[n];  // dynamic array
    arr[0] = 123;
    delete[] arr;

    return 0;
}
