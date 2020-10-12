#include <iostream>
//#include <cstdlib>


using namespace std;


void print_array(float* a, int n)
{
    for (int i = 0; i < n; i++)
        cout << *(a + i) << ' ';
    cout << endl;
}


float* input_array(int n)
{
    //float* a = (float*) malloc(n * sizeof *a);
    float* a = new float[n];
    if (a)
    {
        for (int i = 0; i <n; i++)
        {
            // cin >> a[i];
            cin >> *(a + i);
            //cout << ' ' << (a + i) << endl;
        }
        cout << endl;
    }
    return a;
}


float sum_squares(float* a, int n)
{
    float s = 0;
    for (int i = 0; i < n; i++)
        s += *(a + i) * *(a + i);
    return s;
}


int main()
{
    int n;
    cin >> n;
    float* a = input_array(n);
    print_array(a, n);
    cout << sum_squares(a, n) << endl;
    //free(a);
    delete a;
    return 0;
}
