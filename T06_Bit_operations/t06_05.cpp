#include <iostream>
#include <cstdio>
#include <bitset>
using namespace std;


int main() {
    uint32_t a = 0b00011111000110000001101110110110;
    int max_count = -1;
    int count = 0;
    while (true) {
        // cout << bitset<32>(a) << endl;
        if (a & 1) {
            count++;
        }
        else {
            if (count > max_count) {
                max_count = count;
            }
            count = 0;
        }
        // cout << count << endl;
        if (a == 0)
            break;
        a = a >> 1;
    }
    cout << max_count << endl;
    return 0;
}
