#include <iostream>
#include <fstream>
using namespace std;


int f(const char* filename) {
    ifstream finp(filename);
    if (!finp.good()) exit(1);

    int s = 0;
    while (finp.good()) {
        int x;
        finp >> x;
        if (finp.fail())
            break;
        cout << x << ' ';
        s += x;
    }
    cout << endl;
    finp.close();
    return s;
}


int main() {
    cout << f("t14_01.txt") << endl;
    return 0;
}
