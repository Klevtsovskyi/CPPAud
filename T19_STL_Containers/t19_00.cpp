#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <queue>
#define N 20
using namespace std;


void vector_example() {
    int n = 20;
    vector<int> vct;
    vct.reserve(10);
    for (int i = 0; i < n; i++) {
        vct.push_back(i);
        // cout << vct[i] << ends;
        cout << vct.capacity() << ends;
        cout << vct.size() << endl;
    }
}


void array_example() {
    array<int, N> arr;
    for (int i = 0; i < N; i++) {
        arr[i] = i;
        cout << arr[i] << ends;
    }
}


void list_example() {
    int n = 20;
    list<int> lst;
    for (int i = 0; i < n; i++) {
        lst.push_back(i + 10);
        cout << lst.back() << ends;
    }
    cout << endl;

    list<int>::iterator it = lst.begin();
    while (it != lst.end()) {
        cout << *it << ends;
        it++;
    }
    cout << endl;
}


void queue_example() {
    int n = 20;
    queue<int> q;
    for (int i = 0; i < n; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        cout << q.front() << ends;
        q.pop();
    }

}


int main() {

    // vector_example();
    // array_example();
    list_example();
    // queue_example();

    return 0;
}
