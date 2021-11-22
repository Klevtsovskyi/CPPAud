#include <iostream>
#include <fstream>
#include <algorithm>
#include <utility>
#include <map>
#include <unordered_map>
using namespace std;


template<class Container>
void print(const Container& a) {
    cout << "[";
    for (const auto& item: a) {
        cout << item << ", ";
    }
    cout << "]";
}


template<class Key, class Value>
ostream& operator<<(ostream& out, const pair<Key, Value>& p) {
    return out << p.first << ": " << p.second;
}


map<string, int> map_counter(string filename) {
    map<string, int> counter;
    ifstream finp(filename);
    while (finp.good()) {
        string s;
        finp >> s;
        if (finp.fail())
            break;
        if (counter.find(s) == counter.end())
            counter[s] = 1;
        else
            counter[s]++;
    }
    finp.close();
    return counter;
}



multimap<string, int> multimap_counter(string filename) {
    multimap<string, int> counter;
    ifstream finp(filename);
    while (finp.good()) {
        string s;
        finp >> s;
        if (finp.fail())
            break;
        multimap<string, int>::iterator it = counter.find(s);
        if (it == counter.end())
            counter.insert(pair<string, int>(s, 1));
        else
            it->second++;
    }
    finp.close();
    return counter;
}


unordered_map<string, int> unordered_map_counter(string filename) {
    unordered_map<string, int> counter;
    ifstream finp(filename);
    while (finp.good()) {
        string s;
        finp >> s;
        if (finp.fail())
            break;
        if (counter.find(s) == counter.end())
            counter[s] = 1;
        else
            counter[s]++;
    }
    finp.close();
    return counter;
}


int main() {

    // print(map_counter("input.txt"));
    // print(multimap_counter("input.txt"));
    print(unordered_map_counter("input.txt"));

    return 0;
}
