#include <iostream>
using namespace std;


int f(int n) {
    int a = n;
    int i = 0;
    while (a > 1) {
        if (a % 2)
            a = 3 * a + 1;
        else
            a = a / 2;
        i++;
    }
    return i;
}


int main() {
    int maxi = 0;
    int maxj = 0;
    for (int j = 1; j < 1000; j++) {
        int i = f(j);
        if (i > maxi) {
            maxi = i;
            maxj = j;
        }
    }
    cout << maxi << ' ' << maxj << endl;
    return 0;
}
