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

    fout << fixed << setprecision(3);

    unsigned long long int a;
    while (true) {
        finp >> a;
        if (!finp.good())
            break;
        fout << sqrt(a) << endl;
    }

    finp.close();
    fout.close();

    return 0;
}
