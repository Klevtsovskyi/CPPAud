#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    int8_t x = 0b00011010;
    cout << bitset<8>(x) << endl;
    // cout << bitset<8>(x - 1) << endl;
    cout << bitset<8>(x & (x - 1)) << endl;

    // cout << bitset<8>(-x) << endl;
    // cout << bitset<8>(~x + 1) << endl;
    cout << bitset<8>(x & (-x)) << endl;
    return 0;
}
