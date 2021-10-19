#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
    double x, y, z;
    cin >> x;
    cin.ignore(256, ';');
    cin >> y;
    z = pow(x, y);
    cout << fixed << z << endl;
    cout << scientific << z << endl;
    return 0;
}
