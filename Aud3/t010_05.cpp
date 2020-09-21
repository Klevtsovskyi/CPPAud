#include <iostream>


using namespace std;


uint16_t func(uint8_t a, uint8_t b)
{
    return (uint16_t) a + (uint16_t) b;
}


int main()
{
    uint16_t a, b;
    uint16_t s;
    cin >> a >> b;
    cout << a << " " << b << endl;
    s = func( (uint8_t) a, (uint8_t) b);
    cout << s;
    return 0;
}

