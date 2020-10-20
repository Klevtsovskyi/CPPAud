#include <iostream>


using namespace std;


const int N = 5;


void print(float a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << endl;
}


void add(float a[], float b[], float c[], int n)
{
    for (int i = 0; i < n; i++)
        c[i] = a[i] + b[i];
}


float sproduct(float a[], float b[], int n)
{
    float rez;
    for (int i =0; i < n; i++)
        rez += a[i] * b[i];
    return rez;
}


int main()
{
    float a[N] = {1.9, 0.0, 3.7, 9.1, -2.1};
    float b[N] = {7.5, -0.2, 8.3, 9.0, -3.1};
    float c[N];
    add(a, b, c, N);
    print(c, N);
    cout << sproduct(a, b, N) << endl;
    return 0;
}
