#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    uint64_t m, n;
    uint16_t j;
    cin >> m >> j;
    cout << "m          " << bitset<64>(m) << endl;
    n = 1 << j;
    cout << "n = 1 << j " << bitset<64>(n) << endl;
    n = ~n;
    cout << "~n         " << bitset<64>(n) << endl;
    cout << "n & m      " << bitset<64>(n & m) << endl;
    return 0;
}
