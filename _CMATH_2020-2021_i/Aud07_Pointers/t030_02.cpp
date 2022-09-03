#include <iostream>
#include <cmath>


using namespace std;


void print_array(int* a, int n)
{
    for (int i = 0; i < n; i++)
        cout << *(a + i) << ' ';
    cout << endl;
}


int* input_until_zero(int* i)
{
    int m;
    int* a = (int*) malloc(0);
    *i = 0;
    while (true)
    {
        cin >> m;
        //int* b = a;
        if (m == 0)
            break;
        a = (int*) realloc(a, (*i + 1) * sizeof *a);
        //if (a != b)
        //    cout << '!' << a << ' ' << b << endl;
        a[(*i)++] = m;
    }
    return a;
}


int full_qubes(int* a, int n)
{
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        float qr = pow(a[i], 1.0/3.0);
        if (qr == floor(qr))
            k++;
    }
    return k;
}


int main()
{
    int n;
    int* a = input_until_zero(&n);
    print_array(a, n);
    cout << full_qubes(a, n) << endl;
    free(a);
}


