#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    int16_t n, m;
    uint16_t k;
    cin >> n >> k;

    cout << bitset<16>(n) << endl;
    // n = 0000000000001001 (9)
    // k = 3
    // n = 0000000000000001 (1)
    m = 1 << k;  // 0000000000001000
    cout << bitset<16>(m) << endl;
    m = ~m;      // 1111111111110111
    cout << bitset<16>(m) << endl;
    // 0000000000001001 &
    // 1111111111110111
    n = n & m;
    cout << bitset<16>(n) << endl;
    cout << n << endl;
    printf("%X\n", n);

    return 0;
}
