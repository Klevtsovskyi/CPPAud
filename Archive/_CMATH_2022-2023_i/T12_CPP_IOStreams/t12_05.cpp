#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;


int main() {
    ifstream finp;
    ofstream fout;

    finp.open("input.txt");
    fout.open("output.txt");

    while (!finp.eof()) {
        long long int a;
        finp >> a;
        if (!finp.good())
             break;
        double b = sqrt(a);
        fout << fixed << setprecision(3) << b << endl;
    }

    finp.close();
    fout.close();

    return 0;
}
