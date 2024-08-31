#include <iostream>
#include <cstdio>
#include <array>
#include <vector>
#include <list>
#define N 20
using namespace std;


void array_example() {
    array<int, N> arr = {1, 3, 5};
    cout << arr.size() << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << ' ';
    }
    cout << endl;
    for (int x: arr) {
        cout << x << ' ';
    }
    cout << endl;
}


void vector_example() {
    int n = 10;
    vector<int> vct;
    vct.reserve(6);
    cout << vct.size() << ' ';
    cout << vct.capacity() << endl;

    for (int i = 0; i < n; i++) {
        vct.push_back(i);
        cout << vct.size() << ' ';
        cout << vct.capacity() << endl;
    }

    for (int i = 0; i < vct.size(); i++) {
        cout << vct[i] << ' ';
    }
    cout << endl;
    vct.shrink_to_fit();
    cout << vct.size() << ' ';
    cout << vct.capacity() << endl;
}


void list_example() {
    int n = 10;
    list<int> lst;
    for (int i = 0; i < n; i++) {
        lst.push_front(i);
    }
    list<int>::iterator it = lst.begin();
    while (it != lst.end()) {

        cout << *it << ' ';
        it++;
    }
    cout << endl;
}


int main() {
    array_example();
    // vector_example();
    // list_example();

    return 0;
}
