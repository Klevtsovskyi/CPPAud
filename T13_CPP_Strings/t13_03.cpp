#include <iostream>
#include <sstream>
#include <string>
using namespace std;


int f(const string& s) {
    int count = 0;
    stringstream ss;
    ss << s;
    while (ss.good()) {
        string word;
        ss >> word;
        if (ss.fail())
            break;
        if (word.front() == word.back())
            count++;
    }
    return count;
}


int main() {
    string s = "adsda    yiyui zxccvxcv z poijlp    xcvvvcx  igy  ";
    cout << f(s) << endl;
    return 0;
}
