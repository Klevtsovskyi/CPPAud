#include <iostream>
#include <cstdio>
#include <fstream>
#include <ostream>
#include <map>
#include <unordered_map>
#include <utility>
using namespace std;


template<class Container>
void print(const Container& c) {
    cout << '[';
    for (const auto& item: c) {
        cout << item << ", ";
    }
    cout << ']' << endl;
}


template<class Key, class Value>
ostream& operator<<(ostream& out, const pair<Key, Value>& item) {
    return cout << item.first << ": " << item.second;
}


map<string, int> counter_map(const string& filename) {
    map<string, int> counter;
    ifstream f(filename);
    while (f.good()) {
        string word;
        f >> word;
        if (f.fail())
            break;
        if (counter.find(word) == counter.end()) {
            counter[word] = 1;
        }
        else {
            counter[word]++;
        }
    }
    f.close();
    return counter;
}


unordered_map<string, int> counter_unordered_map(const string& filename) {
    unordered_map<string, int> counter;
    ifstream f(filename);
    while (f.good()) {
        string word;
        f >> word;
        if (f.fail())
            break;
        if (counter.find(word) == counter.end()) {
            counter[word] = 1;
        }
        else {
            counter[word]++;
        }
    }
    f.close();
    return counter;
}


int main() {
    // print(counter_map("input.txt"));
    print(counter_unordered_map("input.txt"));

    return 0;
}
