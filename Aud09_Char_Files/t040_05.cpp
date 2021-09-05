#include <iostream>
#include <clocale>


using namespace std;


int f4_remove_spaces(const char* input, const char* output)
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

    char c, c0 = '\0';

    while (true)
    {
        do
        {
            c = fgetc(finp);
            if (c0 && c == '\n')
                c0 = '\n';
        } while (!feof(finp) && (c == ' ' || c == '\t' || c == '\n'));
        if (feof(finp))
            break;

        if (c0)
            fputc(c0, fout);

        do
        {
            fputc(c, fout);
            c = fgetc(finp);
        } while (!feof(finp) && c != ' ' && c != '\t' && c != '\n');

        if (c == '\t' || c == ' ')
            c0 = ' ';
        else
            c0 = '\n';
    }

    fclose(finp);
    fclose(fout);
    return 0;
}


int main()
{
    setlocale(LC_ALL, "Ukrainian");
    f4_remove_spaces("t040_05_input.txt", "t040_05_output4.txt");
    return 0;
}
