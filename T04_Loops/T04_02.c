#include <stdio.h>
void f(int n){
    printf("%i!=", n);
    for (int i = 1; i<n; i++){
        printf("%i*", i);
    }
    printf("%i", n);
}

void g(int n){
   printf("\n%i!=", n);
    for (int i = n; i > 1; i--){
        printf("%i*", i);
    }
    printf("1");

}

int main() {
    int n;
    n = 10;
    f(n);
    g(n);
    return 0;
}
