#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;


void f(istream& inp, ostream& out) {
    while (inp.good()) {
        string line;
        getline(inp, line);
        if (inp.fail())
            break;
        bool prev = false;
        istringstream iss(line);
        while (iss.good()) {
            string word;
            iss >> word;
            if (iss.fail())
                break;
            if (prev && 'a' <= word[0] && word[0] <= 'z') {
                word[0] = word[0] + 'A' - 'a';
            }
            if (
                word == "die" || word == "der" || word == "das" ||
                word == "Die" || word == "Der" || word == "Das"
            ) {
                prev = true;
            }
            else {
                prev = false;
            }
            out << word << ' ';
        }
        out << endl;
    }
}


int main() {
    ifstream finp("t14_02.txt");
    if (!finp.good()) return 1;
    ofstream fout("output.txt");
    if (!fout.good()) return 1;

    f(finp, fout);

    finp.close();
    fout.close();
    return 0;
}
