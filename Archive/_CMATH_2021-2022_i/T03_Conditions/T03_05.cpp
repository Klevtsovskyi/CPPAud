#include <iostream>
#include <cstdio>
using namespace std;


int main() {
    int a, b;
    cin >> a >> b;
    if (a < b)
        cout << a << endl;
    else if (a > b)
        cout << b << endl;
    else
        cout << "Equal" << endl;
    return 0;
}
