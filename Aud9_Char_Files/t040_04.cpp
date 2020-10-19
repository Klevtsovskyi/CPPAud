#include <iostream>
#include <clocale>


using namespace std;


int f1_append(const char* input, const char c)
{
    FILE* f = fopen(input, "a");
    if (!f)
    {
        printf("Could not open file %s \n", input);
        return 1;
    }

    fputc(c, f);
    fclose(f);
    return 0;
}


int f2_insert(const char* input, const char c)
{
    FILE* f = fopen(input, "r+");
    if (!f)
    {
        printf("Could not open file %s \n", input);
        return 1;
    }

    char c0, c1;
    fseek(f, 0, SEEK_END);
    int length = ftell(f);

    fseek(f, 0, SEEK_SET);
    c0 = fgetc(f);
    fseek(f, 0, SEEK_SET);
    fputc(c, f);

    for (int i = 1; i < length; i++)
    {
        fseek(f, i, SEEK_SET);
        c1 = fgetc(f);
        fseek(f, i, SEEK_SET);
        if (c1 == '\n') // '\r'
            i++;
        fputc(c0, f);
        c0 = c1;
    }
    fputc(c0, f);

    fclose(f);
    return 0;
}


int main()
{
    setlocale(LC_ALL, "Ukrainian");
    char c;
    cin >> c;
    f1_append("t040_04.txt", c);
    f2_insert("t040_04.txt", c);
    return 0;
}
