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
    int* v = (int*) calloc(m, sizeof *v);
    if (v)
    {
        for (int j = 0; j < m; j++)
            v[j] = rand() % 100;
    }
    return v;
}


int** rand_matr(int n, int m)
{
    //int** a = new int*[n];
    //int** a = (int**) malloc(n * sizeof **a);
    int** a = (int**) calloc(n, sizeof **a);
    if (a)
    {
        for (int i = 0; i < n; i++)
        {
            a[i] = (int*) calloc(m, sizeof *a[i]);
            for (int j = 0; j < m; j++)
                a[i][j] = rand() % 100;
        }
    }
    return a;
}


int** add_row(int** a, int n, int m, int* v, int k, bool* success) // a
{
    a = (int**) realloc(a, (n + 1) * sizeof **a);
    if (a)
    {
        for (int i = n; i > k; i--)
            a[i] = a[i - 1];
        a[k] = v;
        *success = true;
        return a;
    }
    *success = false;
    return a;
}


void free_matr(int** a, int n, int m)
{
    for (int i = 0; i < n; i++)
        free(a[i]);
    free(a);
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
