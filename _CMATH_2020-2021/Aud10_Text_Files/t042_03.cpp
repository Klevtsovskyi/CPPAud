#include <iostream>
#include <clocale>
#define N 256


using namespace std;


void bubble_sort(int a[][2], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j][1] < a[j+1][1] ||
                (a[j][1] == a[j+1][1] &&
                 a[j][0] > a[j+1][0]))
            {
                int x = a[j][0];
                int y = a[j][1];
                a[j][0] = a[j+1][0];
                a[j][1] = a[j+1][1];
                a[j+1][0] = x;
                a[j+1][1] = y;
            }
        }
    }
}


int f1(const char* input, const char* output)
{
    int result = 0;
    FILE *finp, *fout;
    finp = fopen(input, "r");
    fout = fopen(output, "w");
    if (!finp|| !fout)
    {
        printf("Could not open files");
        result = 1;
    }
    else
    {
        char c;
        int counter[N];
        for (int i = 0; i < N; i++)
            counter[i] = 0;

        while (!feof(finp))
        {
            c = fgetc(finp);
            counter[(uint8_t) c] += 1;
        }
        //for (int i = 0; i < N; i++)
        //    cout << (uint8_t) i << ' ' << i << ' ' << counter[i] << endl;
        //for (int i = 'à'; i <= 'ÿ'; i++)
        //    cout <<(char)  i << ' ' << i << ' ' << counter[(uint8_t) i] << endl;

        int M = -'à' + 'ÿ' + 1;
        int letters[M][2], k = 0;
        for (int i = 'à'; i <= 'ÿ'; i++)
        {
            letters[k][0] = i;
            letters[k][1] = counter[(uint8_t) i];
            k++;
        }

        bubble_sort(letters, M);
        for(k = 0; k < M; k++)
        {
            if (letters[k][1] == 0)
                break;
            fprintf(fout, "%c - %i\n",
                    letters[k][0],
                    letters[k][1]);
        }
    }

    fclose(finp);
    fclose(fout);
    return result;
}


int main()
{
    setlocale(LC_ALL, "Ukrainian");
    f1("t042_03_input.txt",
       "t042_03_output.txt");
    return 0;
}
