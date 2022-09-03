#include <iostream>
#include <algorithm>
#include <numeric>
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


struct random_int {

    int a, b;
    random_int(int a, int b): a(a), b(b) {}

    int operator()() {
        return rand() % (b - a) + a;
    }
};


int product(int x, int y) {
    return x * y;
}


void algo_example() {
    int n = 5;
    vector<int> v1(n);
    generate(v1.begin(), v1.end(), random_int(1, 5));
    print(v1);

    int s;
    s = 0;
    s = accumulate(v1.begin(), v1.end(), s);
    cout << s << endl;

    s = 1;
    // s = accumulate(v1.begin(), v1.end(), s, product);
    s = accumulate(v1.begin(), v1.end(), s, multiplies<int>());
    cout << s << endl;

    cout << *find_if(v1.begin(), v1.end(), [](int x){return !(x % 2);}) << endl;

    s = 0;
    s = inner_product(v1.begin(), v1.end(), v1.begin(), s);
    cout << s << endl;

}


int main() {
    srand(time(nullptr));

    algo_example();

    return 0;
}
