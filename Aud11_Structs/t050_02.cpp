#include <iostream>


using namespace std;


typedef struct
{
    char w;
    int h;
} Field;


bool queen_can_move(Field a, Field b)
{
    char dw = (char) abs(a.w - b.w);
    int dh = (int) abs(a.h - b.h);
    if (dw == 0 || dh == 0 || dw == dh)
        return true;
    else
        return false;
}


void print_move(Field a, Field b)
{
    cout << a.w << a.h << ' ' <<
            b.w << b.h << ' ' <<
            queen_can_move(a, b) << endl;
}


int main()
{
    Field A = {'a', 1}, B = {'h', 8}, C = {'a', 5}, E, D;
    D.w = 'b';
    D.h = 4;
    E = {.w = 'c', .h = 5};
    print_move(A, B);
    print_move(A, C);
    print_move(A, D);
    print_move(A, E);
    print_move(C, D);
    print_move(C, E);
    print_move(B, C);

    return 0;
}
