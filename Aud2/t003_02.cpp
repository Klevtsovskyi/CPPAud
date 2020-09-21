#include <iostream>
#include <cmath>


using namespace std;


float func1(float x, float y);


int main()
{
    float x, y, f;
    cin >> x >> y;
    f = func1(x, y);
    cout << f << endl;
    return 0;
}


float func1(float x, float y)
{
    return pow(x, 3) + 3 * pow(x, 2) * y + 3 * x * pow(y, 2) + pow(y, 3);
}
