#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;


template<class Container>
void print(const Container& c) {
    cout << "[";
    for (const auto& item: c) {
        cout << item << ", ";
    }
    cout << "\b\b]" << endl;
}


int main() {
    system("color F0");
    vector<int> v1 = {-6, 9, -4, 3, 7, 1, 2};
    int arr[] = {-6, 9, -4, 3, 7, 1, 2};
    sort(arr, arr + 7);
    sort(v1.begin(), v1.end(), greater<int>());
    print(v1);
    print(arr);

    cout << accumulate(v1.begin(), v1.end(), 1, [](int x, int y){return x * y;}) << endl;
    cout << *find_if(v1.begin(), v1.end(), [](int x){return (x % 2) == 0;}) << endl;

    cout << inner_product(
      v1.begin(), v1.end(), v1.begin(), 1,
      plus<int>(), multiplies<int>()
    ) << endl;

    return 0;
}
