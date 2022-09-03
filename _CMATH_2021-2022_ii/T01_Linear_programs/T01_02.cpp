#include <iostream>
#include <cmath>
#define _USE_MATH_DEFINES

using std::cout;
using std::endl;


int main() {
    float x1 = 1e-4;
    printf("%f\n", x1);
    float x2 = 24.33e5;
    printf("%.2e\n", x2);
    float x3 = M_PI;
    printf("%.2f\n", x3);
    float x4 = M_E;
    cout << x4 << endl;
    double x5 = sqrt(5);
    printf("%.2lf\n", x5);
    double x6 = log(100);
    printf("%.2lf\n", x6);
    return 0;
}

