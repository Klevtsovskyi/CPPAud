#include <stdlib.h>
#include <stdio.h>
#define F "F.int32"
#define G "G.int32"
#define N 100


void input_until_zero_to_file(char* filename) {
    FILE* f = fopen(filename, "wb");
    if (!f) exit(1);

    int n = 0;
    int arr[N];
    while (1) {
        scanf("%ld", &arr[n]);
        if (arr[n] == 0)
            break;
        n++;
    }
    fwrite(arr, sizeof (int), n, f);

    fclose(f);
}


void even_numbers_to_file(char* filename_inp, char* filename_out) {
    FILE* inp = fopen(filename_inp, "rb");
    if (!inp) exit(1);
    FILE* out = fopen(filename_out, "wb");
    if (!out) exit(1);

    int num;
    while (fread(&num, sizeof (int), 1, inp)) {
        if (num % 2 == 0)
            fwrite(&num, sizeof (int), 1, out);
    }

    fclose(inp);
    fclose(out);
}


void print_int_from_file(char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) exit(1);

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    int k = size / sizeof (int);

    fseek(f, 0, SEEK_SET);
    for (int i = 0; i < k; i++) {
        int num;
        fread(&num, sizeof (int), 1, f);
        printf("%ld ", num);
    }
    printf("\n");

    fclose(f);
}


int main() {
    input_until_zero_to_file(F);
    even_numbers_to_file(F, G);
    print_int_from_file(F);
    print_int_from_file(G);
    return 0;
}
