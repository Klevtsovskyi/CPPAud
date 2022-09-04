#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    uint32_t n = 0b11101101000111100001100001010101;
    int count = 0;
    int max_count = -1;
    while (n) {
        if (n & 1) {
            count++;
        }
        else {
            if (count > max_count)
                max_count = count;
            count = 0;
        }
        n >>= 1;
    }
    cout << max_count << endl;
    return 0;
}
