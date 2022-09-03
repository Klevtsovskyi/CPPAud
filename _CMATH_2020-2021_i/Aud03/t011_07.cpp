#include <iostream>
#include <cmath>


using namespace std;


int quad_eq(float a, float b, float c, float *x1, float *x2)
{
    int n;
    float d;
    if (a == 0)
    {
        if (b == 0)
        {
            if (c == 0)
                n = -1;
            else
                n = -2;
        }
        else
        {
            n = 1;
            *x1 = -c / b;
        }
    }
    else
    {
        d = b * b - 4 * a * c;
        if (d < 0)
            n = 0;
        else if (d == 0)
        {
            n = 1;
            *x1 = - b / (2 * a);
        }
        else
        {
            n = 2;
            *x1 = (-b - sqrt(d)) / (2 * a);
            *x2 = (-b + sqrt(d)) / (2 * a);
        }
    }
    return n;
}


int biquad_eq(float a, float b, float c, float *x1, float *x2, float *x3, float *x4)
{
    int n;
    n = quad_eq(a, b, c, x1, x2);

    if (n == 1)
    {
        if (*x1 > 0)
        {
            n = 2;
            *x1 = sqrt(*x1);
            *x2 = -*x1;
        }
        else if (*x1 == 0);
        else
            n = 0;
    }
    else if (n == 2)
    {
        if (*x1 > 0)
        {
            *x1 = sqrt(*x1);
            if (*x2 > 0)
            {
                n = 4;
                *x2 = sqrt(*x2);
                *x3 = -*x1;
                *x4 = -*x2;
            }
            else if (*x2 == 0)
            {
                n = 3;
                *x3 = -*x1;
            }
            else
                *x2 = -*x1;
        }
        else if (*x1 == 0)
        {
            if (*x2 > 0)
            {
                n = 3;
                *x2 = sqrt(*x2);
                *x3 = -*x2;
            }
            else
                n = 1;
        }
        else
        {
            if (*x2 > 0)
            {
                *x2 = sqrt(*x2);
                *x1 = -*x2;
            }
            else if (*x2 == 0)
            {
                n = 1;
                *x1 = *x2;
            }
            else
                n = 0;
        }
    }
    return n;
}


int main()
{
    int n;
    float a, b, c, x1, x2, x3, x4;
    cin >> a >> b >> c;
    n = quad_eq(a, b, c, &x1, &x2);
    cout << "Quadratic equation: " << n << endl;
    switch(n)
    {
    case -2:
        cout << "None\n";
        break;
    case -1:
        cout << "Inf\n";
        break;
    case 0:
        cout << "0 solutions\n";
        break;
    case 1:
        cout << x1 << endl;
        break;
    case 2:
        cout << x1 << ' ' << x2 << endl;
        break;
    }


    n = biquad_eq(a, b, c, &x1, &x2, &x3, &x4);
    cout << "Biquadratic equation: " << n << endl;
    switch(n)
    {
    case -1:
        cout << "Inf\n";
        break;
    case 0:
        cout << "0 solutions\n";
        break;
    case 1:
        cout << x1 << endl;
        break;
    case 2:
        cout << x1 << ' ' << x2 << endl;
        break;
    case 3:
        cout << x1 << ' ' << x2 << ' ' << x3 << endl;
        break;
    case 4:
        cout << x1 << ' ' << x2 << ' ' << x3 << ' ' << x4 << endl;
        break;
    default:
        cout << "None\n";
    }

    return 0;
}
