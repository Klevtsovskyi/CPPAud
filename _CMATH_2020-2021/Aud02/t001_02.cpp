#include <iostream>
#include <cmath>


using namespace std;


int main()
{
    float x, d, m;
    cin >> x;
    m = modf(x, &d); // modff, modfl for C
    printf("%f = %f + %f\n", x, d, m);
    printf("%i %i %i\n\n",
           (int) ceil(x) - 1,
           (int) floor(x) + 1,
           (int) round(x)); // int(x) for C++
    int n;
    n = (int) x;
    d = (float) n;
    m = x - d;
    printf("%f = %f + %f\n", x, d, m);
    printf("%i %i %i\n\n",
           (int) (m == 0 ? x - 1 : x),
           (int) x + 1,
           (int) (x + 0.5)); // only for x > 0

    return 0;
}
