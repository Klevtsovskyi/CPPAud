#include <iostream>


using namespace std;


int main()
{
    short n;
    unsigned long long x;
    cin >> n; // 0 <= n <= 63
    x = 1 << n; // 1 --> 1000..000
    cout << x << endl;
    return 0;
}
