#include <iostream>
#include <bitset>
using namespace std;


int main() {
    uint32_t n = 0x0103070F;
    cout << bitset<32>(n) << endl;
    uint32_t left8 = n >> 24;  // 0x00000001
    uint32_t right8 = n << 24; // 0x0F000000
    n = (n >> 8) << 8;  // 0x01030700
    n = (n << 8) >> 8;  // 0x00030700
    n = left8 | right8 | n;
    cout << bitset<32>(n) << endl;
    return 0;
}
