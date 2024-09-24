#include <iostream>
#include <bitset>
using namespace std;


int main() {
    uint64_t n, k;
    cin >> n >> k;
    // 0 <= k < 64
    // n = 00110111 = 55
    // k = 2
    int a = ~(1 << k);
    // a = 11111011
    int b = n & a;
    // b = 00110011 = 51
    cout << b << endl;
    cout << hex << b << endl;
    printf("%llX", b);
    return 0;
}
