#include <iostream>


using namespace std;


float func1(int n, float x)
{
    float s = 1, a = 1;
    int i = 0;
    while (i++ < n)
    {
        a *= x;
        s += a;
    }
    return s;
}


int main()
{
    int n;
    float x;
    cin >> n >> x;
    cout << func1(n, x) << endl;
    return 0;
}
