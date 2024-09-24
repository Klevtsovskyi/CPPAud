#include <iostream>
#include <bitset>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    // 0 <= k < 32
    // n = 00110111 = 55
    // k = 3
    int a = 1 << k;
    // a = 00001000
    int b = n | a;
    // b = 00111111 = 63
    cout << b << endl;

    return 0;
}
