#include <iostream>
using namespace std;

struct A {virtual ~A() = default;};
struct B: public A {virtual ~B() = default;};

void static_cast__example() {
    double d = 54.321;
    int i = static_cast<int>(d);
    cout << i << endl;
    const int& j = static_cast<const int&>(d);
    cout << j << endl;

    void* ptr = static_cast<void*>(&d);

    A* a1 = new A();
    B* b1 = static_cast<B*>(a1);  // downcast

    A* a2 = new B();
    B* b2 = static_cast<B*>(a2);  // downcast

    B* b3 = new B();
    A* a3 = static_cast<A*>(b3);  // upcast

    delete a1, a2, b3;
}
void dynamic_cast__example() {
    A* a1 = new A();
    B* b1 = dynamic_cast<B*>(a1);  // downcast
    cout << b1 << endl;

    A* a2 = new B();
    B* b2 = dynamic_cast<B*>(a2);  // downcast
    cout << b2 << endl;

    B* b3 = new B();
    A* a3 = dynamic_cast<A*>(b3);  // upcast
    cout << a3 << endl;

    A a4;
    B& b4 = dynamic_cast<B&>(a4);  // downcast

    delete a1, a2, b3;
}


int main() {
    system("color F0");
    // static_cast__example();
    dynamic_cast__example();

    return 0;
}
