#include <iostream>
#include <iomanip>
using namespace std;


int main() {
    double x = 42.1234;

    // cout.flags(ios::scientific);

    cout << fixed;
    cout << setprecision(2); // cout.precision(2);
    cout << setw(10); // cout.width(10);
    cout << setfill('@'); // cout.fill('@');
    cout << left;
    cout << x << endl;
    cout << defaultfloat << setprecision(-1) << x << endl;

    int a = 63;
    cout << oct;
    cout << a << endl;
    cout << hex;
    cout << uppercase << a << endl;
    cout << nouppercase << a << endl;

    bool b = 1;
    cout << boolalpha << b << endl;
    cout << noboolalpha << b << endl;

    cout << dec;
    int *arr = new int[5];
    for (int i = 0; i < 5; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    delete[] arr;

    return 0;
}
