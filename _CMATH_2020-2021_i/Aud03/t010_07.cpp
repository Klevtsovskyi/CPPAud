#include <iostream>
#include <climits>


using namespace std;


void mult(uint64_t a, uint64_t b, uint64_t *c, uint64_t *d)
{
    // a = ma * 10^5 + na // ma, na ~ 10^5
    // b = mb * 10^5 + nb // mb, nb ~ 10^5
    // a * b = ma * mb * 10^10 + (ma * nb + mb * na) * 10^5 + na * nb
    uint64_t ma, na, mb, nb, x1, x2, x3;

    ma = a / 100000;
    na = a % 100000;
    mb = b / 100000;
    nb = b % 100000;

    x1 = na * nb;
    x2 = ma * nb + mb * na;
    x3 = ma * mb;

    *d = x1 + (x2 % 100000) * 100000;
    *c = x3 + x2 / 100000;

    *c = *c + *d / 10000000000;
    *d = *d % 10000000000;
}


// 4444444444 * 4444444444
// 19753086415802469136
int main()
{
    uint64_t a, b, c, d;
    // cout << ULLONG_MAX;
    scanf("%10llu%10llu", &a, &b);
    cout << a << ' ' << b << endl;
    mult(a, b, &c, &d);
    printf("%llu%010llu", c, d);
    return 0;
}
