#include <iostream>
#include <cstdio>
#include <climits>
using namespace std;


uint32_t sum(uint32_t a, uint32_t b,
             int* overflow) {
    uint32_t c = a + b;
    if (a > UINT_MAX - b) {
        *overflow = 1;
    }
    else {
        *overflow = 0;
    }
    return c;
}


int main() {
    uint32_t a, b, c;
    int overflow;
    cin >> a >> b;
    c = sum(a, b, &overflow);
    if (overflow)
        cout << "Overflow!" << endl;
    cout << c;

    return 0;
}
