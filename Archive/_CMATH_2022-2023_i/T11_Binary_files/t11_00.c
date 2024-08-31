#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 100


void text() {
    FILE* f = fopen("input.txt", "r");
    if (!f)
        exit(1);

    while (true) {
        char c = fgetc(f);
        if (c == EOF) {
            break;
        }
        printf("%c", c);
    }
    rewind(f);
    printf("\n\n");
    while (true) {
        char s[101];
        char* ptr = fgets(s, 10, f);
        if (ptr == NULL)
            break;
        printf("%s", s);
    }
    fclose(f);

    f = fopen("output.txt", "w");
    if (!f)
        exit(1);

    for (int i = 0; i < 100; i++) {
        fprintf(f, "%ld ", i);
    }
    fclose(f);
}


void binary() {
    FILE* f = fopen("F.int32", "wb");
    if (!f) exit(1);

    int n = 5;
    int a[N] = {0, 1, 2, -1, 897};
    fwrite(a, sizeof (int), n, f);
    fclose(f);

    f = fopen("F.int32", "rb");
    if (!f) exit(1);

    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    int k = size / sizeof (int);
    int b[N];

    fseek(f, 0, SEEK_SET);
    fread(b, sizeof (int), k, f);
    for (int i = 0; i < k; i++)
        printf("%ld ", b[i]);
    printf("\n");

    k = 3;
    fseek(f, k * sizeof (int), SEEK_SET);
    int x;
    fread(&x, sizeof (int), 1, f);
    printf("%ld\n", x);
    fclose(f);
}


int main() {
    // text();
    binary();
    return 0;
}
