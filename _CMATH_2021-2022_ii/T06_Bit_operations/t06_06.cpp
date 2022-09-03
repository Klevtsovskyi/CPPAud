#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


// x           = 0000110000010000
// x - 1       = 0000110000001111
// x & (x - 1) = 0000110000000000

//  x          = 0010001100011110
// -x = ~x + 1 = 1101110011100010
//  x & (-x)   = 0000000000000010


int main() {
    int16_t n = 0b0010001100011000;
    cout << bitset<16>(n) <<  endl;
    cout << bitset<16>(~n + 1) <<  endl;
    cout << bitset<16>(-n) <<  endl;
    cout << bitset<16>(n & (-n)) <<  endl;
    return 0;
}
