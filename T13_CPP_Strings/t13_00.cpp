#include <iostream>
#include <string>
using namespace std;


int main() {
    string s1("abc");
    string s2 = "abc";
    string s3(s2);
    string s4('a' + s3 + "abc", 1);

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;

    s1.erase(1);
    cout << s1 << endl;

    for (int i = 0; i < s4.length(); i++) {
        cout << s4[i] << ' ';
    }
    cout << endl;
    for (char c: s4) {
        cout << c << ' ';
    }
    cout << endl;

    int i = s4.find("abc");
    cout << i << endl;
    i = s4.rfind("abc");
    cout << i << endl;

    return 0;
}
