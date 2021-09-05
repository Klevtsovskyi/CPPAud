#include <iostream>


using namespace std;


const int N = 10;


void transpose(int a[N][N], int n)
{
    int x;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
          x = a[i][j];
          a[i][j] = a[j][i];
          a[j][i] = x;
        }
    }
}


void print(int a[][N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << ' ';
        cout << endl;
    }
}


void swap(int a[N][N], int n, int x, int y)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == x)
            {
                a[i][j] = y;
                return;
            }
        }
    }
}


int main()
{
    int a[N][N] = {{1, 2, 3,}, {4, 5, 6}, {7, 8, 9}};
    transpose(a, 3);
    swap(a, 3, 8, 0);
    print(a, 3);
    return 0;
}
