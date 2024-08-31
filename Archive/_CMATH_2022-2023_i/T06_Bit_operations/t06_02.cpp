#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    uint16_t n, k, m;
    cin >> n >> k;
    cout << "n          " << bitset<16>(n) << endl;
    m = 1 << k;
    cout << "m = 1 << k " << bitset<16>(m) << endl;
    cout << "n | m      " << bitset<16>(n | m) << ' ' << (n | m) << endl;
    return 0;
}
