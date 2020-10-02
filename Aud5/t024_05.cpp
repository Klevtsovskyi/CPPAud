#include <iostream>


using namespace std;


int lbit(unsigned n)
{
    int i = 0;
    while (n != 0)
    {
        if (n & 1 == 1)
            return i;
        n >>= 1;
        i++;
    }
    return -1;
}


int hbit(unsigned n)
{
    unsigned m = 1 << 31;
    for (int i = 31; i >= 0; i--)
    {
        if (m <= n)
            return i;
        m >>= 1;
    }
    return -1;
}


int main()
{
    unsigned M;
    cin >> M;
    cout << lbit(M) << endl;
    cout << hbit(M) << endl;
    return 0;
}
