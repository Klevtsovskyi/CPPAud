#include <iostream>
#include <vector>
#include <ostream>
using namespace std;


template<class T>
ostream& operator << (ostream& out, const vector<T>& v) {
    out << '[';
    for (int i = 0; i < v.size() - 1; i++)
        out << v[i] << ", ";
    out << v.back() << ']';
    return out;
}


void vector__exmaple() {
    int n = 3;
    vector<int> v(n, 1);

    for (int i = 0; i < 5; i++) {
        v.push_back(i);
        cout << "size: " << v.size() << endl;
        cout << "capacity: " << v.capacity() << endl;
    }

    for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
        cout << *it << ' ';
    }
    cout << endl;

    cout << v << endl;
}



int main() {
    vector__exmaple();

    return 0;
}
