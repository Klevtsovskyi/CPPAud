#include <iostream>
#include <cstdio>
using namespace std;


typedef struct {
    struct {
        int x, y;
    } p1, p2;
} Rect;


void print(Rect a) {
    cout << a.p1.x << ends << a.p1.y << endl <<
    a.p2.x << ends << a.p2.y << endl;
}


Rect input() {
    Rect a;
    cin >> a.p1.x >> a.p1.y >> a.p2.x >> a.p2.y;
    return a;
}


int main() {
    Rect r = {
        {1, 0},
        {2, 3}
    };
    print(r);
    Rect t = input();
    print(t);
    return 0;
}
