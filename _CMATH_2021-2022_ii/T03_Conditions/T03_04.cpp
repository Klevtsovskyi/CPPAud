#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;


uint16_t product(uint8_t a, uint8_t b) {
    uint16_t c = (uint16_t) a * b;
    return c;
}


int main() {
    uint8_t x, y; // char x, y;
    uint16_t z;
    cin >> z;
    x = (uint8_t) z;
    cin >> z;
    y = (uint8_t) z;
    z = product(x, y);
    cout << z << endl;
    return 0;
}
