#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    int8_t a = 13;
    int8_t b = 54;
    cout << "a      " << bitset<8>(a) << ' ' << (int16_t) a << endl;
    cout << "b      " << bitset<8>(b) << ' ' << (int16_t) b << endl;
    cout << "~a     " << bitset<8>(~a) << ' ' << ~a << endl;
    cout << "a&b    " << bitset<8>(a&b) << ' ' << (a&b) << endl;
    cout << "a|b    " << bitset<8>(a|b) << ' ' << (a|b) << endl;
    cout << "a^b    " << bitset<8>(a^b) << ' ' << (a^b) << endl;
    cout << "a<<1    " << bitset<8>(a<<1) << ' ' << (a<<1) << endl;
    cout << "a>>1    " << bitset<8>(a>>1) << ' ' << (a>>1) << endl;

    return 0;
}
