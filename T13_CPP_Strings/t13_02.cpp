#include <iostream>
#include <string>
using namespace std;


string f1(const string& s) {
    int i = s.find('.');
    int j = s.rfind('.');
    if (i != -1 && j != -1) {
        return s.substr(0, i) + s.substr(j + 1);
    }
    else {
        int k;
        for (k = 0; k < s.length(); k++) {
            if (s[k] != ' ')
                break;
        }
        return s.substr(k);
    }
}


void f2(string& s) {
    int i = s.find('.');
    int j = s.rfind('.');
    if (i != -1 && j != -1) {
        s.erase(i, j - i + 1);
    }
    else {
        int k;
        for (k = 0; k < s.length(); k++) {
            if (s[k] != ' ')
                break;
        }
        s.erase(0, k);
    }
}


int main() {
    string s;
    getline(cin, s);
    cout << f1(s) << endl;
    f2(s);
    cout << s << endl;
    return 0;
}
