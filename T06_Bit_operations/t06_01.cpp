#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    uint16_t n;
    cin >> n;
    uint64_t k;
    k = 1 << n;
    cout << k << endl;
    cout << bitset<64>(k) << endl;
    return 0;
}
