#include <iostream>
#include <cmath>
using namespace std;


void hyp(double a, double b, double* c) {
    (*c) = hypot(a, b);
}


int main() {
    double a, b, c;
    cin >> a >> b;
    cout << c << endl;
    hyp(a, b, &c);
    cout << c << endl;
    return 0;
}
