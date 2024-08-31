#include <iostream>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;


template <class T>
bool compare(const vector<T>& a, const vector<T>& b) {
    T maxa = *max_element(a.begin(), a.end());
    T maxb = *max_element(b.begin(), b.end());
    return maxa > maxb;
}


template <class T>
struct Comparator {
    bool operator()(const vector<T>& a, const vector<T>& b) {
        T maxa = *max_element(a.begin(), a.end());
        T maxb = *max_element(b.begin(), b.end());
        return maxa > maxb;
    }
};


vector<vector<int> > random_matrix(int n, int m) {
    vector<vector<int> > matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
    return matrix;
}


template <class T>
ostream& operator<<(ostream& out, const vector<vector<T> >& matrix) {
    for (const vector<T>& row: matrix) {
        for (const T& item: row) {
            out << item << ' ';
        }
        out << endl;
    }
    return out;
}


int main() {
    srand(time(nullptr));

    int n = 7;
    int m = 3;
    vector<vector<int> > matrix = random_matrix(n, m);
    cout << matrix << endl;
    // sort(matrix.begin(), matrix.end(), compare<int>);
    sort(matrix.begin(), matrix.end(), Comparator<int>());

    cout << matrix << endl;

    return 0;
}
