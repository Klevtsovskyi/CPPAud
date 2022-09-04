#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;


int main() {
    double x, res;
    int n;
    cin >> x >> n;
    res = x;
    for (int i = 0; i < n; i++) {
        res = sin(res);
    }
    cout << res << endl;
    return 0;
}
