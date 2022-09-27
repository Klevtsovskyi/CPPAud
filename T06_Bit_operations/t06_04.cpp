#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    uint32_t a = 0b00011101000110000001100011110110;
    uint32_t left8, right8;
    cout << a << endl;
    cout << bitset<32>(a) << endl;
    left8 = a >> 24;
    right8 = a << 24;
    cout << bitset<32>(left8) << endl;
    cout << bitset<32>(right8) << endl;
    a = a << 8 >> 8;
    a = a >> 8 << 8;
    cout << bitset<32>(a) << endl;
    a = a | left8 | right8;
    cout << bitset<32>(a) << endl;
    cout << a << endl;
    printf("%X", a);
    return 0;
}
