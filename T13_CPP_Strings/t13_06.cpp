#include <iostream>
#include <string>
#include <sstream>
#include <climits>
using namespace std;


const int A = 0;
const int B = 1;
const int C = 2;


string shortest_word(const string& s, int mode=A) {
    string result;

    istringstream iss(s);
    if (mode == A) {
        string word;
        while (iss.good()) {
            iss >> word;
            if (iss.fail())
                break;
            if (result.length() == 0 || word.length() < result.length()) {
                result = word;
            }
        }
    }

    if (mode == B) {
        string word;
        while (iss.good()) {
            iss >> word;
            if (iss.fail())
                break;
            if (result.length() == 0 || word.length() <= result.length()) {
                result = word;
            }
        }
    }

    if (mode == C) {
        int min_length = INT_MAX;

        while (iss.good()) {
            string word;
            iss >> word;
            if (iss.fail())
                break;
            if (word.length() < min_length) {
                min_length = word.length();
            }
        }

        iss.seekg(0, istringstream::beg);

        ostringstream oss;
        while (iss.good()) {
            string word;
            iss >> word;
            if (iss.fail())
                break;
            if (word.length() == min_length) {
                min_length = word.length();
                oss << word << ' ';
            }
        }
    result = oss.str();
    }
    return result;
}


int main() {
    string text("asd   a    asd aa b c     zxc");
    // getline(cin, text);
    cout << shortest_word(text, A) << endl;
    cout << shortest_word(text, B) << endl;
    cout << shortest_word(text, C) << endl;

    return 0;
}
