#include <iostream>
#include <cstdio>
using namespace std;


int main() {
    int arr[] = {5, 112, 4, 3};
    for (int i = sizeof(arr) / sizeof(int) - 1; i >= 0; i--) {
        cout << arr[i] << ends;
    }
    cout << endl;
    return 0;
}
