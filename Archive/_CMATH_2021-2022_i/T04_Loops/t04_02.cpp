#include <iostream>
#include <cstdio>
#include <cfloat>
using namespace std;


int main() {

    int i;
    int fact = 1;
    int n = 10;
    cout << "n! = ";
    for (i = 1; i < n; i++) {
        cout << i << '*';
        fact *= i;
    }
    fact *= i;
    cout << i << " = " << fact << endl;

    fact = 1;
    cout << "n! = ";
    for (i = n; i > 1; i--) {
        cout << i << '*';
        fact *= i;
    }
    fact *= i;
    cout << i << " = " << fact << endl;

    return 0;
}
