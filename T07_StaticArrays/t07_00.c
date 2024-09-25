#include <stdio.h>
#define N 50

void print(const int* arr, const int n) {
    for (int i = 0; i < n; i++)
        printf("%li ", arr[i]);
    printf("\n");
}
void input(int* arr, int n) {
    for (int i = 0; i < n; i++)
        scanf("%li", &arr[i]);
        // scanf("%li", arr + i);
}

int main() {
    int n = 5;
    int arr[N];  // = {2, 4, 6, 1, 3};
    input(arr, n);
    print(arr, n);
    // printf("size: %lu\n", sizeof(arr) / sizeof(arr[0]));
    // printf("%p\n", arr);

    // for (int i = 0; i < n; i++)
    //     printf("%p %p\n", &arr[i], arr + i);


    return 0;
}