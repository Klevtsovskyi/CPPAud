#include <iostream>
#include <cstring>
#define N 200


using namespace std;


bool check_brackets(char* s)
{
    bool closed = true;
    for (int i = 0; i < strlen(s); i++)
    {
        if (s[i] == '(')
        {
            if (!closed)
                return false;
            closed = false;
        }
        else if (s[i] == ')')
        {
            if (closed)
                return false;
            closed = true;
        }
    }
    return closed;
}


void erase_brackets(char* s)
{
    int j = 0;
    bool closed = true;
    int n = strlen(s);
    char* cpy = new char[n];
    strcpy(cpy, s);
    for (int i = 0; i < n; i++)
    {
        if (cpy[i] == '(')
            closed = false;
        else if (cpy[i] == ')')
        {
            closed = true;
            continue;
        }
        if (closed)
            s[j++] = cpy[i];
    }
    s[j] = '\0';
    delete cpy;
}


int main()
{
    char* s = new char[N];
    fgets(s, N, stdin);
    if (check_brackets(s))
        erase_brackets(s);
    cout << s << endl;
    delete s;
    return 0;
}
