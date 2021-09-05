#include <iostream>
// #include <cassert>


using namespace std;


class AssertionError: public logic_error
{
public:

    AssertionError(const char* message): logic_error(message) {}
};


void Assert(bool expression, const char* message="")
{
    if (!expression)
        throw AssertionError(message);
}


unsigned to_num(char c, int base)
{
    // c: '0'-'9' -> 0-9
    // 'a'-'f' -> 10-15
    unsigned m;
    char message[50];
    sprintf(message, "Symbol %c is not under base %i", c, base);
    Assert('0' <= c && c < '0' + min(10, base) ||
           'a' <= c && c < 'a' + (base < 10 ? 0 : base % 10),
           message);
    if ('0' <= c && c < '0' + min(10, base))
        m = c - '0';
    else
        m = 10 + c - 'a';
    return m;
}


unsigned to_int(string s, int base)
{
    char message[50];
    sprintf(message, "The base %i is not in range [2, 16]", base);
    Assert(2 <= base && base <= 16, message);
    unsigned result = 0;
    for (int i = 0; i < s.length(); i++)
    {
        unsigned m = to_num(s[i], base);
        result = (result * base) + m;
    }
    return result;
}


int main()
{
    try
    {
        unsigned base;
        string s;
        cin >> base;
        Assert(!cin.fail(), "The base is not a number!");
        cin >> s;
        unsigned n = to_int(s, base);
        cout << n << endl;
    }
    catch (AssertionError& e)
    {
        cout << "Incorrect data! " << e.what() << endl;
    }
    return 0;
}
