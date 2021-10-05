#include <stdio.h>
#include <stdlib.h>


int main() {
    int* a;
    int* b;
    printf("%p %p\n\n", a, b);
    printf("%p %p\n\n", &a, &b);
    printf("%16llu %16llu\n\n", sizeof a, sizeof b);
    printf("%16llu %16llu\n\n", sizeof *a, sizeof *b);

    a = (int*) malloc(10 * sizeof *a);
    b = (int*) calloc(10, sizeof *b);

    printf("%p %p\n\n", a, b);

    for (int i = 0; i < 10; i++)
        *(a + i) = i; // <=> a[i] = i;

    for (int i = 0; i < 10; i++)
        b[i] = i + 10;

    for (int i = 0; i < 10; i++)
        printf("%16ld %16ld\n", *(a + i), b[i]);

    printf("\n");
    int* c = a;
    a = (int*) realloc(a, 11 * sizeof *a);
    a[10] = -1;
    for (int i = 0; i < 11; i++)
    printf("%16ld\n", *(a + i));

    printf("\n%p %p\n\n", a, c);

    free(a);
    free(b);

    int* d = (int*) malloc(1 * sizeof *d);
    printf("\n%p %p\n\n", d, c);
    *d = 1;
    c = d;
    d = (int*) realloc(d, 2 * sizeof *d);
    *(d + 1) = 2;
    printf("\n%p %p\n\n", d, c);

    free(d);

    return 0;
}
