#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;


vector<vector<int> > random_matrix(int n, int m) {
    vector<vector<int> > matrix(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            matrix[i][j] = rand() % 100;
    }
    return matrix;
}


template<class T>
ostream& operator<<(ostream& out, const vector<vector<T> >& matrix) {
    for (const vector<T>& row: matrix) {
        for (const T& item: row)
            out << item << ends;
        out << endl;
    }
    return out;
}


int main() {
    srand(time(nullptr));

    int n = 3;
    int m = 6;

    vector<vector<int> > matrix = random_matrix(n, m);
    cout << matrix;

    return 0;
}
