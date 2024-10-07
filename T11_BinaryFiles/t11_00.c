#include <stdio.h>
#include <stdlib.h>
#define N 100


int main() {
    int n = 6;
    int arr[N] = {1, 0, 9, -1, 888, 56431}, arr2[N];

    FILE* f = fopen("file.int32", "wb");

    fwrite(&n, sizeof (int), 1, f);
    fwrite(arr, sizeof (int), n, f);

    fclose(f);

    f = fopen("file.int32", "rb");

    while (1) {
        int m;
        int size = fread(&m, sizeof (int), 1, f);
        if (size == 0)
            break;
        printf("%li ", m);
    }
    printf("\n");
    fclose(f);

    f = fopen("file.int32", "rb");
    fseek(f, 0, SEEK_END);
    int size = ftell(f);
    printf("\nsize: %li\n", size);
    n = size / sizeof (int);
    printf("count: %li\n", n);

    rewind(f); // fseek(f, 0, SEEK_SET);
    fread(arr2, sizeof (int), n, f);
    for (int i = 0; i < n; i++) {
        printf("%li ", arr2[i]);
    }
    printf("\n");

    fclose(f);

    return 0;
}
