#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;


template<class Container>
void print(const Container& a) {
    cout << "[";
    for (const auto& item: a) {
        cout << item << ", ";
    }
    cout << "]" << endl;
}


void iterator_example() {
    vector<int> v = {3, 4, 2, -2, 4, 6, 43, 0, 1, 5};

    cout << *v.begin() << ends;
    cout << *(v.end() - 1) << endl;

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << ends;
        *it = *it + 1;
    }
    cout << endl;

    for (vector<int>::const_iterator it = v.cbegin(); it != v.cend(); it++) {
        cout << *it << ends;
    }
    cout << endl;

    for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) {
        cout << *it << ends;
    }
    cout << endl;

    sort(v.rbegin(), v.rend());

    for (vector<int>::const_reverse_iterator it = v.crbegin(); it != v.crend(); it++) {
        cout << *it << ends;
    }
    cout << endl;


}


void set_example() {
    set<int> s1 = {6, 7, 3, 1, 0, -3, 4, -8};
    set<int> s2 = {0, 1, 3, 2, 5, 8};

    s1.insert(5);
    s1.insert(6);
    s1.erase(3);
    print(s1);
    print(s2);

    vector<int> v(max(s1.size(), s2.size()));

    vector<int>::iterator it = set_difference(
        s1.begin(), s1.end(), s2.begin(), s2.end(), v.begin()
    );
    // print(v);
    set<int> s3(v.begin(), it);
    print(s3);
}


int main() {
    // iterator_example();
    set_example();

    return 0;
}
