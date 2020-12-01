#include <iostream>
#include <map>
#include <fstream>


using namespace std;


map<string, int> counter(string filename)
{
    map<string, int> dict;
    ifstream finp;
    finp.open(filename);
    while (true)
    {
        string word;
        finp >> word;
        if (finp.fail())
            break;
        if (dict.find(word) == dict.end())
            dict[word] = 1;
        else
            dict[word]++;
    }
    finp.close();
    return dict;
}


template <class K, class V>
ostream& operator<<(ostream& out, const pair<K, V>& p)
{
    out << '"' << p.first << "\": " << p.second;
    return out;
}


template <class K, class V>
ostream& operator<<(ostream& out, const map<K, V>& m)
{
    out << "{";
    for (auto& p: m)
        out << p << ", ";
    cout << "}";
    return out;
}


int main()
{
    map<string, int> dict = counter("input.txt");
    cout << dict << endl;
    return 0;
}
