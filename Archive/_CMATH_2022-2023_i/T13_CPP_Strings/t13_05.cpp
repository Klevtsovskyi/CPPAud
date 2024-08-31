#include <iostream>
#include <string>
#include <cstring>
using namespace std;


string* split(const string& s, const char* delim, int n) {
    string* a = new string[n];
    int start = 0;
    int finish = 0;
    for (int i = 0; i < n; i++) {
        finish = s.find(delim, start);
        if (finish == -1) {
            a[i] = s.substr(start);
            break;
        }

        a[i] = s.substr(start, finish - start);
        start = finish + strlen(delim);
    }
    return a;
}


int main() {
    int n = 5;
    string s = "45a;mmm; 031azxf;d; asd;abc;zxc";
    string* a = split(s, "; ", n);
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }

    delete[] a;
    return 0;
}
