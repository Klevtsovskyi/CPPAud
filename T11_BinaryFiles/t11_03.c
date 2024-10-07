#include <stdio.h>
#include <stdlib.h>
#define N 100
#define F "input.int32"
#define G "output.int32"


void input_until_zero(const char* filename) {
    FILE* f = fopen(filename, "wb");
    if (!f)
        exit(1);

    while (1) {
        int m;
        scanf("%li", &m);
        if (m == 0)
            break;
        fwrite(&m, sizeof (m), 1, f);
    }
    fclose(f);
}
void print(const char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f)
        exit(1);

    fseek(f, 0, SEEK_END);
    int n = ftell(f) / sizeof (int);

    rewind(f);
    int arr[N];
    fread(arr, sizeof (int), n, f);

    for (int i = 0; i < n; i++)
        printf("%li ", arr[i]);
    printf("\n");

    fclose(f);
}


void a(const char* input, const char* output) {
    FILE* finp = fopen(input, "rb");
    if (!finp) exit(1);
    FILE* fout = fopen(output, "wb");
    if (!fout) exit(1);

    while (1) {
        int m;
        fread(&m, sizeof (int), 1, finp);
        if (feof(finp))
            break;
        if (m % 2 == 0)
            fwrite(&m, sizeof (int), 1, fout);
    }
    fclose(finp);
    fclose(fout);
}


int main() {
    input_until_zero(F);
    print(F);

    a(F, G);
    print(G);

    return 0;
}
