#include <iostream>


using namespace std;


unsigned long long fact1(int n)
{
    unsigned long long rez = 1;
    for (int i = 1; i <= n; i++)
        rez *= i;
    return rez;
}


unsigned long long fact2(int n)
{
    unsigned long long rez = 1;
    for (int i = n; i > 0; i--)
        rez *= i;
    return rez;
}


int main()
{
    int n;
    cin >> n;
    cout << fact1(n) << endl;
    cout << fact2(n) << endl;
    return 0;
}
