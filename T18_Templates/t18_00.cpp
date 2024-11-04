#include <iostream>
using namespace std;


namespace my {

    template<typename T>
    T f(T t) {
        // ...
        return t;
    }

    namespace a {
        namespace b {
            char f(char c) {
                return c;
            }
        }
    }
}

template<class T, class K>
class MyClass {
public:
    T t;
    K k;

    MyClass(T t, K k): t(t), k(k) {}
};


int main() {
    int i = 432;
    cout << my::f<int>(i) << endl;

    double d = 567.12;
    cout << my::f<double>(d) << endl;

    cout << my::a::b::f('a') << endl;

    MyClass<int, double> obj(987, 435.21);
    cout << obj.t << ' ' << obj.k << endl;

    return 0;
}
