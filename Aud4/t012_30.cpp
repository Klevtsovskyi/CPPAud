#include <iostream>


using namespace std;


unsigned long long fib(int n)
{
    unsigned long long f0 = 0, f1 = 1, f2;
    for (int i = 0; i < n; i++)
    {
        f2 = f0 + f1;
        f0 = f1;
        f1 = f2;
    }
    return f0;
}


int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
