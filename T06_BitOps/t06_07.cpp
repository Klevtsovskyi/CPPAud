#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


void test() {
    uint32_t x = 0x0F070301;
    cout << bitset<32>(x) << endl;
    uint8_t* ptr = (uint8_t*) &x;
    // printf("%p\n", ptr);
    // printf("%p\n", ptr + 1);
    for (int i = -3; i < 4; i++)
        cout << bitset<8>(*(ptr + i)) << ' ';
    cout << endl;
}


void endian() {
    uint32_t x = 1;
    uint8_t* ptr = (uint8_t*) &x;
    if (*ptr)
        cout << "little endian" << endl;
    else if (*(ptr + 3))
        cout << "big endian" << endl;
    else
        cout << "middle endian" << endl;
}


int main() {
    endian();
    return 0;
}
