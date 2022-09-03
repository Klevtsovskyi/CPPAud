#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    int16_t n, m;
    uint16_t k;
    cin >> n >> k;

    cout << bitset<16>(n) << endl;
    // n = 0000000000001001
    // k = 1
    // n = 0000000000001011
    m = 1 << k;  // 0000000000000010
    cout << bitset<16>(m) << endl;
    n = n | m;  // 0000000000001001 & 0000000000000010
    cout << bitset<16>(n) << endl;
    cout << n << endl;
    return 0;
}
