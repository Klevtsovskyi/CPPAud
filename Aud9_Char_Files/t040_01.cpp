#include <iostream>
#include <cctype>
#include <clocale>


using namespace std;


int f1(const char* input, const char* output)
{
    FILE* finp = fopen(input, "r");
    if (!finp)
    {
        printf("Could not open file %s \n", input);
        return 1;
    }

    FILE* fout = fopen(output, "w");
    if (!fout)
    {
        printf("Could not open file %s \n", output);
        fclose(finp);
        return 1;
    }

    char c = fgetc(finp);
    while (!feof(finp))
    {
        if (isupper(c))
            c -= 'A' - 'a';
        fputc(c, fout);
        c = fgetc(finp);
    }

    fclose(finp);
    fclose(fout);
    return 0;
}


int f2(const char* input, const char* output)
{
    FILE* finp = fopen(input, "r");
    if (!finp)
    {
        printf("Could not open file %s \n", input);
        return 1;
    }

    FILE* fout = fopen(output, "w");
    if (!fout)
    {
        printf("Could not open file %s \n", output);
        fclose(finp);
        return 1;
    }

    int i = 0;
    char c;
    do
    {
        fseek(finp, --i, SEEK_END);
        c = fgetc(finp);
        if (c == '\n')
            i--;
        fputc(c, fout);
    } while (ftell(finp) != 1);

    fclose(finp);
    fclose(fout);
    return 0;
}


int main()
{
    setlocale(LC_ALL, "Ukrainian");
    f1("t040_01_input.txt", "t040_01_output1.txt");
    f2("t040_01_input.txt", "t040_01_output2.txt");
    return 0;
}
