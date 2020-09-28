#include <iostream>
#include <cmath>


using namespace std;


int main()
{
    int n;
    float x;
    cin >> n >> x;
    for (int i = 0; i < n; i++)
    {
        x = sin(x);
    }
    cout << x << endl;
    return 0;
}
