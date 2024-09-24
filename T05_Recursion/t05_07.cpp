#include <iostream>
using namespace std;


double f(int n) {
    double p = 2.0;
    double a1 = 0.0;
    double a2 = 1.0;
    double a3;
    double b1 = 1.0;
    double b2 = 0.0;
    double b3;
    double s = 0;
    for (int k = 3; k < n + 3; k++) {
        s += p / (a1 + b1);
        p *= 2.0;
        b3 = b2 + a2;
        a3 = a2 / k + a1 * b3;
        a1 = a2;
        a2 = a3;
        b1 = b2;
        b2 = b3;
    }
    return s;
}


int main() {
    int k;
    cin >> k;
    cout << f(k) << endl;
    return 0;
}
