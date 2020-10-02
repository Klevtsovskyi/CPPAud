#include <iostream>


using namespace std;


void bin(int n)
{
    for (int i = 31; i >= 0; i--)
        cout << ((n >> i) & 1);
    cout << endl;
}


void bin(short n)
{
    short bits[16];
    for (int i = 0; i < 16; i++)
    {
        bits[i] = n & 1;
        n >>= 1;
    }
    for (int i = 15; i >= 0; i--)
        cout << bits[i];
    cout << endl;
}



int main()
{
    short n;
    cin >> n;
    bin((int) n);
    bin(n);
    return 0;

    // x & (x - 1)
    // прибирає найнижчий значущий (1) біт
    // 11011 & 11010 = 11010
    // 10110 & 10101 = 10100
    // 10100 & 10011 = 10000

    // x & (-x) = x & (~x + 1)
    // повертає 2**n, n - номер найнижчого значущого (1) біта
    // 00000110 & 11111010 = 10
    // 00001100 & 11110100 = 100
}
