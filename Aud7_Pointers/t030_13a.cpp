#include <iostream>
#include <ctime>


using namespace std;


void print_matr(int** a, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    cout << endl;
}


int* rand_vect(int m)
{
    int* v = new int[m];
    if (v)
    {
        for (int j = 0; j < m; j++)
            v[j] = rand() % 100;
    }
    return v;
}


int** rand_matr(int n, int m)
{
    int** a = new int*[n];
    if (a)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = new int[m];
            for (int j = 0; j < m; j++)
                a[i][j] = rand() % 100;
        }
    }
    return a;
}


int** add_row(int** a, int n, int m, int* v, int k, bool* success) // a
{
    int** b = new int*[n + 1];
    if (b)
    {
        for (int i = 0; i < k; i++)
            b[i] = a[i];
        b[k] = v;
        for (int i = k + 1; i < n + 1; i++)
            b[i] = a[i - 1];
        delete a;
        *success = true;
        return b;
    }
    *success = false;
    return a;
}


void free_matr(int** a, int n, int m)
{
    for (int i = 0; i < n; i++)
        delete a[i];
    delete a;
}


int main()
{
    srand(time(NULL));
    int n, m, *v, **a;
    bool success;

    cin >> n >> m;
    a = rand_matr(n, m);
    if (a)
        print_matr(a, n, m);

    v = rand_vect(m);
    a = add_row(a, n, m, v, 0, &success);
    if (success)
        n++;
    if (a)
        print_matr(a, n, m);

    free_matr(a, n, m);

    return 0;
}
