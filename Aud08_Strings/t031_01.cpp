#include <iostream>
#include <cstring>
#define N 200


using namespace std;


void f1(char s[], char rez[])
{
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == '\0')
        {
            rez[j] = '\0';
            break;
        }
        else if ('0' <= s[i] && s[i] <= '9')
            continue;
        else if (s[i] == '+' || s[i] == '-')
            rez[j++] = s[i];

        rez[j] = s[i];
        j++;
    }
}


void f2(char s[], char rez[])
{
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == '\0')
        {
            rez[j] = '\0';
            break;
        }
        else if (s[i] == '+' && isdigit(s[i + 1]))
            continue;

        rez[j] = s[i];
        j++;
    }
}


void f3(char s[], char rez[])
{
    int j = 0, ct =0;
    for (int i = 0; i < N; i++)
    {
        if (s[i] == '\0')
        {
            rez[j] = '\0';
            break;
        }
        else if (s[i] == 'b')
        {
            ct++;
            continue;
        }
        else if (s[i] == 'c')
            ct = 0;
        else
        {
            for (int k = 0; k < ct; k++)
                rez[j++] = 'b';
            ct = 0;
        }

        rez[j] = s[i];
        j++;
    }
}


void f4_replace(char s[], const char from[], const char to[])
{
    int j = 0, k = 0;
    int n = strlen(s);
    char cpy[N];
    strcpy(cpy, s);
    for (int i = 0; i < n; i++)
    {
        for (k = 0; k < strlen(from); k++)
        {
            if (cpy[i + k] != from[k])
                break;
        }
        if (k == strlen(from))
        {
            for (k = 0; k < strlen(to); k++)
                s[j++] = to[k];
            i += strlen(from) - 1;
            continue;
        }
        s[j++] = cpy[i];
    }
    s[j] = '\0';
}


void f5_clear_spaces(char s[])
{
    int j = 0, k = 0;
    int n = strlen(s);
    char cpy[N];
    strcpy(cpy, s);
    for (int i = 0; i < n; i++)
    {
        if (cpy[i] == ' ' && cpy[i + 1] == ' ')
            continue;
        s[j++] = cpy[i];
    }
    s[j] = '\0';
}


int main()
{
    char s[N], rez[N];
    fgets(s, N, stdin);
    //f1(s, rez);
    //f2(s, rez);
    //f3(s, rez);
    //f4_replace(s, "phi", "f");
    f5_clear_spaces(s);
    cout << s << endl;
    //cout << rez << endl;
    return 0;
}
