#include <iostream>


using namespace std;


double sum1(int n)
{
    double a1 = 0, a2 = 1, a3, b = 2, s = 0;
    for (int i = 2; i <= n; i++)
    {
        a3 = a2 + i * a1;
        a1 = a2;
        a2 = a3;
        b *= 2;
        s += b * a1;
    }
    return s;
}


int main()
{
    int n;
    cin >> n;
    cout << sum1(n) << endl;
    return 0;
}
