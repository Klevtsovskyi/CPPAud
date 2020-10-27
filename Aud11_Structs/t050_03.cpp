#include <iostream>


using namespace std;


typedef unsigned int uint;


typedef struct
{
    int numerator;
    uint denominator;
} Rational;


uint gcd(uint a, uint b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}


Rational to_irreducible(Rational x)
{
    int d = gcd((uint) abs(x.numerator), x.denominator);
    x.numerator /= d;
    x.denominator /= d;
    return x;
}


Rational sum(Rational x, Rational y)
{
    Rational z;
    z.numerator = x.numerator * y.denominator +
                  y.numerator * x.denominator;
    z.denominator = x.denominator * y.denominator;
    return to_irreducible(z);
}


Rational product(Rational x, Rational y)
{
    Rational z;
    z.numerator = x.numerator * y.numerator;
    z.denominator = x.denominator * y.denominator;
    return to_irreducible(z);
}


int compare(Rational x, Rational y)
{
    x.numerator *= y.denominator;
    y.numerator *= x.denominator;
    if (x.numerator == y.numerator)
        return 0;
    else if (x.numerator > y.numerator)
        return 1;
    else
        return -1;
}


void print(Rational x)
{
    printf("%i/%u\n", x.numerator, x.denominator);
}


int main()
{
    Rational x[8];
    x[0] = {1, 4};
    x[1] = {3, 6};
    x[2] = {-3, 5};
    x[3] = {2, 3};
    x[4] = {-2, 10};
    x[5] = to_irreducible(x[4]);
    x[6] = sum(x[0], x[2]);
    x[7] = product(x[2], x[3]);
    for (int i = 0; i < 8; i++)
        print(x[i]);

    cout << compare(x[0], x[1]) << endl;
    cout << compare(x[0], x[0]) << endl;
    cout << compare(x[3], x[0]) << endl;
    return 0;
}
