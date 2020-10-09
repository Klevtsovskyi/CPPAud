#include <iostream>
#include <ctime>


using namespace std;


const int N = 5;


int main()
{
    float x;
    int a[N];
    srand(time(NULL));
    for (int i = 0; i < N; i++)
        a[i] = rand() % 100;
    for (int i = 0; i < N; i++)
        cout << a[i] << ' ';
    cout << endl;
    cin >> x;
    for (int i =0; i < N; i++)
    {
        if (a[i] < x)
            cout << a[i] << ' ';
    }
    cout << endl;

    return 0;
}
