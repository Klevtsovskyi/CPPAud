#include <iostream>


using namespace std;


unsigned long long ffact(int n)
{
    unsigned long long rez = 1;
    int i = n;
    for(; i > 0; i -= 2)
        rez *= i;
    return rez;
}


int main()
{
    int n;
    cin >> n;
    cout << ffact(n) << endl;
    return 0;
}
