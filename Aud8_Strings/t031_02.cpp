#include <iostream>
#include <cstring>
#define N 200


using namespace std;


int first_index_of(char* s, char c)
{
    char* ptr = strchr(s, c);
    return ptr == NULL ? -1 : ptr - s;
}


int last_index_of(char* s, char c)
{
    char* ptr = strrchr(s, c);
    return ptr == NULL ? -1 : ptr - s;
}


int count_of(char* s, char c)
{
    int ct = 0;
    char* ptr = strchr(s, c);
    while (ptr != NULL)
    {
        ct++;
        ++ptr = strchr(ptr, c);
    }
    return ct;
}


int main()
{
    char* s = new char[N];
    fgets(s, N, stdin);
    cout << first_index_of(s, ',') << endl;;
    cout << last_index_of(s, ',') << endl;;
    cout << count_of(s, ',') << endl;;
    delete s;
    return 0;
}

