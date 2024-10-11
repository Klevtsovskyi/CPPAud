#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
using namespace std;


int main() {
    ifstream finp("input.txt");
    ofstream fout("output.txt");
    if (!finp.is_open()) exit(1);
    if (!fout.is_open()) exit(2);

    fout << fixed << setprecision(3);
    while (!finp.eof()) {
        long long int n;
        finp >> n;
        if (!finp.good())
            break;
        fout << sqrt(n) << '\n';
    }

    finp.close();
    fout.close();

    return 0;
}
