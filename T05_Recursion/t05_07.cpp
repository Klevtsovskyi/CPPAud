#include <iostream>
using namespace std;


double f(int n) {
    double s, a1, a2, a3, b1, b2, b3, p;
    s = 0.0;
    p = 1.0;
    a1 = 0.0;
    a2 = 1.0;
    b1 = 1.0;
    b2 = 0.0;
    for (int k = 1; k <= n; k++) {
        p *= 2.0;
        s += p / (a1 + b1);
        // cout << a1 << endl;
        // cout << b1 << endl;
        // cout << p / (a1 + b1) << endl;
        b3 = b2 + a2;
        b1 = b2;
        b2 = b3;
        a3 = a2 / (k + 2.0) + a1 * b3;
        a1 = a2;
        a2 = a3;
    }
    return s;
}


int main() {
    cout << f(3) << endl;
    return 0;
}
