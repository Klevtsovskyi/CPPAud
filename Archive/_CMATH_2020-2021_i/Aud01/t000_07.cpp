#include <iostream>


using namespace std;


int main()
{
    float T;
    T = 1 + 1.0 / 3;
    //cout << T << endl;
    T = 7 + 1.0 / T;
    T = 4 + 1.0 / T;
    T = 365 + 1.0 / T;
    printf("%.10f\n", T);
    T = 365 + 1.0 / (4 + 1.0 / (7 + 1.0 / (1 + 1.0 / 3)));
    printf("%.10f\n", T);
    return 0;
}
