#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;


typedef struct Struct {
    int n;
    char s[29];
    Struct* next;
} Struct;


int main() {
    system("color 70");
    Struct* a = (Struct*) malloc(sizeof(*a));
    (*a).n = 10;
    strcpy((*a).s, "Hello!");
    a->next = a;
    printf("%li %s\n", a->n, a->s);
    printf("%p %p\n", a, a->next);
    printf("size: %lli\n", sizeof(*a));
    free(a);

    return 0;
}
