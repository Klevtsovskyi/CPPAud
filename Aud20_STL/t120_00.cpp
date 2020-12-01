#include <iostream>
#include <vector>
#include <set>
// #include <unordered_set>
#include <map>
// #include <unordered_map>
#include <algorithm>


using namespace std;


template <class Collection>
void print(Collection& c)
{
    cout << "[";
    for (auto x: c)
        cout << x << ", ";
    cout << "]" << endl;
}


template <class T>
class compare
{
public:
    bool operator()(const T a, const T b) const
    {
        return (a > b);
    }
};


void vector_example()
{
    vector<int> a = {2, 3, 6, 6, 4, 5, 7, 9, 0, -1};
    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << ' ';
    cout << endl;
    cout << a.back() << endl;
    a.pop_back();
    a.push_back(6);
    for (int i = 0; i < a.size(); i++)
        cout << a.at(i) << ' ';
    cout << endl;
    a.insert(a.begin() + 1, 3);
    for (vector<int>::const_iterator it = a.begin();
         it != a.end(); it++)
        cout << (*it) << ' ';
    cout << endl;
    a.erase(a.begin() + 1);
    for (auto it = a.begin(); it != a.end(); it++)
        cout << (*it) << ' ';
    cout << endl;

    cout << count(a.begin(), a.end(), 6) << endl;

    vector<int> b(5, 1);
    print(b);
    fill(b.begin(), b.end(), 2);
    print(b);
    // b.resize(a.size());
    // print(b);
    // copy(a.begin(), a.end(), b.begin());
    // print(b);
    b.assign(a.begin(), a.end());
    print(b);

    sort(b.begin(), b.end(), compare<int>());
    print(b);
}


void set_example()
{
    set<int> a = {3, 2, 1, 4};
    a.insert(5);
    a.insert(5);
    a.erase(5);
    print(a);

    set<int> b = {2, 3, 0, 6};
    print(b);

    vector<int> v(max(a.size(), b.size()));

    vector<int>::iterator it = set_intersection(a.begin(), a.end(),
                                                b.begin(), b.end(),
                                                v.begin());
    // v.resize(it - v.begin());
    print(v);
    set<int> c;
    c.insert(v.begin(), it);
    print(c);
}


void map_example()
{
    map<string, int> a;
    pair<string , int> p("a", 1);
    cout << p.first << ' ' << p.second << endl;
    a.insert(p);
    a.insert({"b", 2});
    a["c"] = 3;
    cout << "size: " << a.size() << endl;
    cout << "a[\"a\"] = " << a["a"] << endl;
    cout << endl;
    for (auto it = a.begin(); it != a.end(); it++)
        cout << it->first << ' ' << it->second << endl;

    a.erase("a");
    cout << "size: " << a.size() << endl;
}


int main()
{
    // vector_example();
    // set_example();
    map_example();
    return 0;
}
