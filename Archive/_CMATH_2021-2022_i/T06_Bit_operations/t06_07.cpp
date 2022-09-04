#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


void test() {
    uint32_t n = 0x0103070F;
    cout << bitset<32>(n) << endl;
    uint8_t* ptr = (uint8_t *) &n;

    for (int i = 0; i < 4; i++)
        cout << bitset<8>( *(ptr + i)) << endl;
}


void endian() {
    uint32_t n = 1;
    uint8_t* ptr = (uint8_t *) &n;
    if (*ptr) {
        cout << "little endian" << endl;
    } else if (*(ptr + 3)) {
        cout << "big endian" << endl;
    } else {
        cout << "middle endian" << endl;
    }
}


int main() {
    endian();
    return 0;
}
