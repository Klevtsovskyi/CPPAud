#include <iostream>
using namespace std;


double pa(int n) {
    double p = 1.0;
    double f = 1.0;
    for (int i = 1; i <= n; i++) {
        f *= i;
        p *= (1.0 + 1.0 / f);
        // cout << (1.0 + 1.0 / f) << endl;
        // cout << p << endl;
    }
    return p;
}


int main() {
    cout << pa(5) << endl;
    return 0;
}
