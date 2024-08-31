#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    uint16_t n;
    uint64_t res;
    cin >> n;
    res = 1 << n;
    cout << bitset<64>(res) << ' ' << res << endl;

    return 0;
}
