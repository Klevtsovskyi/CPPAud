#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main() {
    // Конструктори рядка
    string s1;
    string s2("string");
    string s3 = "string";
    string s4(s3);

    // Дії над рядками
    cout << s2 + ' ' + s3 << endl;
    s4.insert(1, "HELLO!");
    cout << s4 << endl;
    s4.erase(2, 3);
    cout << s4 << endl;
    s4.replace(1, 2, "CPP");
    cout << s4 << endl;

    // Зрізка рядка
    cout << s4.substr(1, 4) << endl;

    // Ітерація по рядку
    for (int i = 0; i < s4.size(); i++)
        cout << s4[i] << ' ';
    cout << endl;
    for (char c: s4)
        cout << c << ' ';
    cout << endl;

    // Пошук символів та рядків в рядку
    cout << s4.find('P', 0) << endl;
    cout << s4.rfind('P', s4.size() - 1) << endl;

    // Рядкови потік (як cin та cout)
    stringstream ss;
    ss << "Objects of this     class use a        string. buffer that contains a  sequence of. characters. This sequence. of characters can be accessed directly as a string object, using member str";
    while (ss.good()) {
        string s;
        ss >> s;
        cout << s << endl;
    }

    // Розбиття рядку
    string text(ss.str());
    // cout << text << endl;
    cout << endl;
    int i = 0;
    int j = 0;
    while ((j = text.find('.', i)) != -1) {
        cout << "substr: " << text.substr(i, j - i) << endl;
        i = j + 1;
    }
    cout << "substr: " << text.substr(i, text.size() - i) << endl;

    return 0;
}
