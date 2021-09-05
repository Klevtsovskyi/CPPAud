#include <iostream>
#include <cmath>
#define N 10


using namespace std;


int main()
{
    double a[N];
    for (int i = 0; i < N; i++)
        cin >> a[i];
    double s = 0;
    for (int i = 0; i < N; i++)
    {
        if (a[i] > M_E)
            s += a[i];
    }
    cout << s << endl;
    return 0;
}
