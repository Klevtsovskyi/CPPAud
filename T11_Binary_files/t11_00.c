#include <stdio.h>
#include <stdlib.h>
#define F "F.int32"
#define N 100


void example_text_files() {
    FILE* f = fopen("input.txt", "r");
    if (!f) exit(1);

    while (1) {
        char c = fgetc(f);
        if (c == EOF)
            break;
        printf("%c", c);
    }

    rewind(f);
    while (1) {
        char s[100];
        char* ptr = fgets(s, 99, f);
        if (ptr == NULL)
            break;
        printf("%s", s);
    }

    fclose(f);

    f = fopen("output.txt", "w");
    if (!f) exit(1);

    for (int i = 0; i < 100; i++)
        fprintf(f, "%ld ", i);

    fclose(f);
}


void example_binary_files() {
    FILE* f = fopen(F, "wb");
    if (!f) exit(1);

    int n = 5;
    int arr[N] = {1, 2, 3, -1, 777};
    fwrite(arr, sizeof (int), n, f);

    fclose(f);

    f = fopen(F, "rb");
    if (!f) exit(1);

    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    int k = size / sizeof (int);

    fseek(f, 0, SEEK_SET);
    int arrr[N];
    fread(arrr, sizeof (int), k, f);
    for (int i = 0; i < k; i++)
        printf("%ld ", arrr[i]);
    printf("\n");

    k = 4;
    fseek(f, (k - 1) * sizeof (int), SEEK_SET);
    int num;
    fread(&num, sizeof (int), 1, f);
    printf("%ld\n", num);
    fclose(f);
}


int main() {
    // example_text_files();
    // example_binary_files();
    return 0;
}
