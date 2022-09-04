#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;


template<class Container>
void print(const Container& a) {
    cout << "[";
    for (const auto& item: a) {
        cout << item << ", ";
    }
    cout << "]" << endl;
}


class BoolVector: public vector<bool> {

public:

    BoolVector(int n = 0, bool f = false): vector<bool>(n, f) {}

    static BoolVector random(int n) {
        BoolVector result(n);
        generate(result.begin(), result.end(), [](){return (bool) (rand() % 2);});
        return result;
    }

    int count(bool b = true) {
        return std::count(cbegin(), cend(), b);
    }

    BoolVector logical_and(const BoolVector& other) {
        if (size() != other.size())
            throw logic_error("");
        BoolVector result(size());
        transform(
            begin(), end(), other.begin(), result.begin(),
            std::logical_and<bool>()
        );
        return result;
    }

    BoolVector logical_or(const BoolVector& other) {
        if (size() != other.size())
            throw logic_error("");
        BoolVector result(size());
        transform(
            begin(), end(), other.begin(), result.begin(),
            std::logical_or<bool>()
        );
        return result;
    }

    BoolVector logical_not() {
        BoolVector result(size());
        transform(begin(), end(), result.begin(), std::logical_not<bool>());
        return result;
    }
};


int main() {
    srand(time(nullptr));

    int n = 10;
    BoolVector bv1 = BoolVector::random(n);
    BoolVector bv2 = BoolVector::random(n);

    print(bv1);
    print(bv2);

    cout << bv1.count(true) << ends << bv1.count(false) << endl;
    cout << bv2.count(true) << ends << bv2.count(false) << endl;

    print(bv1.logical_and(bv2));
    print(bv1.logical_or(bv2));
    print(bv1.logical_not());

    return 0;
}
