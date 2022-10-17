#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100


void input_until_zero(char* filename) {
    FILE* f = fopen(filename, "wb");
    if (!f) exit(1);

    int n = 0;
    int a[N];
    while (true) {
        int x;
        scanf("%ld", &x);
        if (x == 0)
            break;
        a[n++] = x;
    }
    fwrite(a, sizeof (int), n, f);
    fclose(f);
}


void print_from_file(char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) exit(1);

    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    int count = size / sizeof (int);

    fseek(f, 0, SEEK_SET);
    for (int i = 0; i < count; i++) {
        int x;
        fread(&x, sizeof (int), 1, f);
        printf("%ld ", x);
    }
    printf("\n");
    fclose(f);
}


void even_ints(char* fname_input, char* fname_output) {
    FILE* finp = fopen(fname_input, "rb");
    if (!finp) exit(1);
    FILE* fout = fopen(fname_output, "wb");
    if (!fout) exit(1);

    int x;
    while (fread(&x, sizeof (x), 1, finp)) {
        if (x % 2 == 0) {
            fwrite(&x, sizeof (x), 1, fout);
        }
    }
    fclose(finp);
    fclose(fout);
}


int main() {
    char F[N] = "F.int32";
    char G[N] = "G.int32";
    input_until_zero(F);
    print_from_file(F);
    even_ints(F, G);
    print_from_file(G);

    return 0;
}
