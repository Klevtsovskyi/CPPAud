#include <iostream>
#include <climits>


using namespace std;


uint32_t add(uint32_t a, uint32_t b, int *overflow)
{
    uint32_t c = 0;
    if (UINT_MAX - a < b)
        *overflow = 1;
    else
    {
        *overflow = 0;
        c = a + b;
    }
    return c;
}


int main()
{
    uint32_t a, b, c;
    int overflow;
    // cout << UINT_MAX << endl;
    cin >> a >> b;
    c = add(a, b, &overflow);
    if (overflow)
        cout << "Overflow\n";
    else
        cout << c << endl;

    // int32_t
    // INT_MIN INM_MAX
    return 0;
}

