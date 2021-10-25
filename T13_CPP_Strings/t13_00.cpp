#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main() {
    string s1("abc");
    cout << s1 << ends << &s1 << endl;
    string s2 = "abc";
    cout << s2 << ends << &s2 << endl;
    string s3(s2);
    cout << s3 << ends << &s3 << endl;
    string s4 = s3;
    cout << s4 << ends << &s4 << endl;

    const char* str = "123";
    string s5 = s1 + s2 + 'e' + s1[0] + str;
    cout << s5 << endl;

    for (int j = 0; j < s5.length(); j++)
        cout << s5[j] << ends;
    cout << endl;
    for (char c: s5)
        cout << c << ends;
    cout << endl;

    int i;
    cout << (i = s5.find("abc")) << endl;
    cout << (i = s5.rfind("abc")) << endl;

    istringstream iss("   " + s1 + "\t\n      " + s2 + " " + s3);
    ostringstream oss;
    cout << iss.str() << endl;
    string s;
    while (true) {
        iss >> s;
        if (iss.fail())
            break;
        oss << s << ends;
    }

    cout << oss.str() << endl;

    string str1 = "Abc, CVb, Tyu, Iop";
    i = 0;
    int j;
    while ((j = str1.find(",", i)) != -1) {
        cout << str1.substr(i, j - i) << endl;
        i = j + 1;
    }
    cout << str1.substr(i) << endl;


    return 0;
}
