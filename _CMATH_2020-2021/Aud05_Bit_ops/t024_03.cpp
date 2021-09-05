#include <iostream>


using namespace std;


void print_hex(unsigned long long n)
{
    char c, hexes[16];
    int k;
    for (int i = 0; i < 16; i++)
    {
        k = 0;
        for (int j = 0; j < 4; j++)
        {
            k += (n & 1) ? (1 << j) : 0;
            n >>= 1;
        }
        if (0 <= k && k <= 9)
            c = '0' + k;
        else
            c = 'a' + k % 10;
        hexes[i] = c;
    }

    bool zeros = true;
    for (int i = 15; i >=0; i--)
    {
        if (hexes[i] != '0' || !zeros)
        {
            zeros = false;
            cout << hexes[i];
        }
    }
    cout << endl;
}


int main()
{
    short j;
    unsigned long long M, m, x;
    cin >> M >> j;
    m = 1 << j;
    m = ~m;
    x = M & m;
    cout << x << endl;
    print_hex(x);
    cout << hex << x << endl;
    return 0;
}
