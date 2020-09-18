#include <iostream>
#include <cmath>
//#define _USE_MATH_DEFINES


using namespace std;


const float PI = acos(-1.0);


int main()
{
    float h, r, V;
    cin >> h >> r;
    V = h * pow(r, 2) * PI;
    cout << V << endl;
    //printf("%.20lf", M_PI);
    return 0;
}
