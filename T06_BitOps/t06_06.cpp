#include <iostream>
#include <bitset>
using namespace std;


int main() {
    uint8_t x = 0b00111000;
    //  x - 1 = 0b00110111
    //  x & (x - 1) = 0b00110000  // прибирає наймолодший біт
    //  (x & (x - 1)) > 0
    //  вище дасть false, якщо x - нуль, або степінь двійки

    int8_t y = 0b00101110;
    cout << bitset<8>(y) << endl;
    cout << bitset<8>(~y + 1) << endl;
    cout << bitset<8>(-y) << endl;
    // y & (-y) = y & (~y + 1)
    cout << (y & (-y)) << endl;
    // степінь двійки, що відповідає найменшому біту числа
    return 0;
}
