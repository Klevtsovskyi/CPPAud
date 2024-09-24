#include <iostream>
#include <bitset>
using namespace std;


int main() {
    int16_t n;
    //cin >> n;
    n = 0b0011110001111101;
    int maxcount = 0;
    int curcount = 0;
    while (n > 0) {
        if (n & 1) {
            curcount++;
            if (curcount > maxcount)
                maxcount = curcount;
        }
        else {
            curcount = 0;
        }
        n = n >> 1;
    }
    cout << maxcount << endl;

    return 0;
}
