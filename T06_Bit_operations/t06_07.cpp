#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


void test() {
    uint32_t x = 0x0F070301;
    cout << bitset<32>(x) << endl;
    // printf("%p\n", &x);
    uint8_t *ptr = (uint8_t*) &x;
    for (int i = -3; i < 4; i++) {
        // printf("%p\n", ptr + i);
        cout << bitset<8>(*(ptr + i)) << endl;
    }
}


void endian() {
    uint32_t x = 1;
    uint8_t *ptr = (uint8_t*) &x;
    if (*ptr == 1) {
        cout << "little endian" << endl;
    }
    else if (*(ptr + 3) == 1) {
        cout << "big endian" << endl;
    }
    else {
        cout << "middle endian" << endl;
    }
}


int main() {
    endian();
    return 0;
}
