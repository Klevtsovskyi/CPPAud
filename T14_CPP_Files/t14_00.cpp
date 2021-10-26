#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main() {
    ofstream fout("output.txt", ios_base::out | ios_base::app);
    fout << 1234 << endl;
    fout.close();

    ifstream finp("input.txt", ios_base::in);
    if (!finp.good())
        exit(1);
    string s;
    getline(finp, s);
    cout << s << endl;
    finp.close();

    fstream f;
    f.open("output.txt", fstream::in | fstream::out | fstream::ate);
    if (!f.good())
        exit(1);
    f << 654.32 << endl;
    f.seekg(0);
    f << 1000;
    f.close();

    return 0;
}
