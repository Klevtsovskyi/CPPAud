#include <iostream>


using namespace std;


void bin(unsigned n)
{
    for (int i = 31; i >= 0; i--)
        cout << ((n >> i) & 1);
    cout << endl;
}

unsigned reverse8(unsigned n)
{
    unsigned first8, last8;
    last8 = n >> 24;
    first8 = n & 0b11111111; // (1 << 8) - 1
    n = n & ((1 << 24) - 1);
    n = (n >> 8) << 8;
    n = n | last8;
    n = n | (first8 << 24);
    return n;
}


int main()
{
    unsigned n;
    cin >> n;
    bin(n);
    n = reverse8(n);
    bin(n);
    cout << n << endl;
    return 0;
}
