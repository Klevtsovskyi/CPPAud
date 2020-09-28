#include <iostream>


using namespace std;


int main()
{
    int i = 0;
    int s = 0, a;
    /*
    do
    {
        printf("a[%i] = ", i++);
        cin >> a;
        s += a;
    } while (a != 0);
    */
    while (true)
    {
        printf("a[%i] = ", i++);
        cin >> a;
        s += a;
        if (a == 0)
            break;
    }

    cout << s << endl;
    return 0;
}
