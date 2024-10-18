#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;


int main() {
    system("color F0");
    fstream f;
    f.open("input.txt", f.in | f.out);
    if (!f.good())
        exit(1);

    while (f.good()) {
        char line[256];
        f.getline(line, 256);
        cout << line << endl;
    }
    f.clear();
    f.seekp(0, f.end);
    f << "\n" << 123 << ", " << 345 ;

    f.close();

    ifstream inp("input.txt");
    while (inp.good()) {
        string s;
        inp >> s;
        if (inp.fail())
            break;
        cout << s << ' ';
    }
    inp.close();

    return 0;
}
