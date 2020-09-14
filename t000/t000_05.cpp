#include <iostream>
//#include <locale>
#include <windows.h>


using namespace std;


int main()
{
    //setlocale(LC_ALL, "Ukrainian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    unsigned a;
    cout << "Ââåä³òü öèôðó: ";
    cin >> a;
    cout << '\n' << a << ' ' << a << ' ' << a << endl;
    printf("%d %d\n", a, a);
    printf("%d %d %d\n", a, a, a);
    return 0;
}
