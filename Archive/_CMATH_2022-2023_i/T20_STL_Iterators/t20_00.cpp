#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;


template<class Container>
void print(const Container& c) {
    cout << '[';
    for (const auto& item: c) {
        cout << item << ", ";
    }
    cout << ']' << endl;
}


void iterator_example() {
    vector<int> v = {0, -2, 7, 8, 77, 54, -23, -65, 2, 3, 2, 0, -3};

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        (*it)++;
        cout << *it << ' ';
    }
    cout << endl;
    // cout << *(v.end() - 1) << endl;
        for (vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
    for (vector<int>::const_reverse_iterator it = v.crbegin(); it != v.crend(); it++) {
        cout << *it << ' ';
    }
    cout << endl;
}


void set_example() {
    set<int> s1 = {1, 6, -2, 7, 10, 22, 6, 3, 1, 0};
    print(s1);
    set<int> s2 = {2, 3, 10, -2, 0, 3, 1, 1, 9};
    s2.insert(4);
    s2.erase(2);
    print(s2);

    vector<int> v(min(s1.size(), s2.size()));
    vector<int>::iterator it = set_intersection(
        s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin()
    );
    set<int> s3(v.begin(), it);
    print(s3);
}


int main() {
    // iterator_example();
    set_example();

    return 0;
}
