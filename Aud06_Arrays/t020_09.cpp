#include <iostream>
#include <cmath>
#define N 5


using namespace std;


void input(unsigned a[], int n)
{
    for (int i = 0; i < n; i++)
        cin >> a[i];
}


bool is_prime(unsigned m)
{
    if (m == 2)
        return true;
    for (int i = 2; i < sqrt(m) + 1; i++)
    {
        if (m % i == 0)
            return false;
    }
    return true;
}


int full_square(unsigned a[], int n)
{
    int k = 0;
    float sqr;
    for (int i = 0; i < n; i++)
    {
        sqr = sqrt(a[i]);
        if (sqr == floor(sqr) && is_prime((unsigned) sqr))
            k++;
    }
    return k;
}


int main()
{
    unsigned a[N];
    input(a, N);
    cout << full_square(a, N) << endl;
    return 0;
}
