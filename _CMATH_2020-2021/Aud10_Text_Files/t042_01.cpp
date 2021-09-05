#include <iostream>
#include <cstring>
#define N 10


int f1(const char* input1, const char* input2, const char* output)
{
    int result = 0;
    FILE *finp1, *finp2, *fout;
    finp1 = fopen(input1, "r");
    finp2 = fopen(input2, "r");
    fout = fopen(output, "w");
    if (!finp1 || !finp2 || !fout)
    {
        printf("Could not open files");
        result = 1;
    }
    else
    {
        char buffer[N+1];
        int n;
        while (!feof(finp1))
        {
            while (!feof(finp1))
            {
                fgets(buffer, N, finp1);
                n = strlen(buffer);
                if (buffer[n-1] == '\n')
                {
                    buffer[n-1] = '\0';
                    fputs(buffer, fout);
                    break;
                }
                fputs(buffer, fout);
            }
            fputc(' ', fout);

            while (!feof(finp2))
            {
                fgets(buffer, N, finp2);
                n = strlen(buffer);
                if (buffer[n-1] == '\n')
                {
                    buffer[n-1] = '\0';
                    fputs(buffer, fout);
                    break;
                }
                fputs(buffer, fout);
            }
            if (feof(finp2))
                fseek(finp2, 0, SEEK_SET);
            if (!feof(finp1))
                fputc('\n', fout);
        }
    }
    fclose(finp1);
    fclose(finp2);
    fclose(fout);
    return result;
}


int main()
{
    f1("t042_01_input1.txt",
       "t042_01_input2.txt",
       "t042_01_output.txt");
    return 0;
}
