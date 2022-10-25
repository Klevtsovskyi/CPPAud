#include <iostream>
#include <fstream>
#include <string>
#define N 100
using namespace std;


void text() {
    ofstream fout;
    fout.open("output.txt");
    if (!fout.good()) exit(1);

    int i, n = 5, a[N] = {234, 123, 0, 54, -3};
    for (i = 0; i < n - 1; i++) {
        fout << a[i] << ",\n";
    }
    fout << a[i];
    fout.close();

    ifstream finp;
    finp.open("output.txt");
    if (!finp.good()) exit(1);

    while (finp.good()) {
        int x;
        finp >> x;
        if (finp.fail())
            break;
        cout << x << ' ';
        finp.ignore(256, ',');
    }
    cout << endl;
    finp.close();

    finp.open("output.txt");
    if (!finp.good()) exit(1);

    i = 0;
    while (finp.good()) {
        string s;
        getline(finp, s);
        if (finp.fail())
            break;
        i++;
    }
    cout << "Rows: " << i << endl;
    finp.close();

    finp.open("output.txt");
    if (!finp.good()) exit(1);

    while (finp.good()) {
        string s;
        finp >> s;
        if (finp.fail())
            break;
        cout << s << ' ';
    }
    cout << endl;
    finp.close();
}


void binary() {
    ofstream fout("output.int32", ofstream::binary);
    if (!fout.good()) exit(1);

    int n = 5, a[N] = {234, 123, 0, 54, -3};
    fout.write((char*) a, n * sizeof (int));

    fout.close();

    ifstream finp("output.int32", ofstream::binary);
    if (!finp.good()) exit(1);

    finp.seekg(0, ifstream::end);
    cout << finp.tellg() << endl;
    finp.seekg(0);
    while (finp.good()) {
        int x;
        finp.read((char*) &x, sizeof (int));
        if (finp.fail())
            break;
        cout << x << ' ';
    }
    cout << endl;

    finp.close();
}


int main() {
    // text();
    binary();
    return 0;
}
