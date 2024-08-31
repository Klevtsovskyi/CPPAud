#include <iostream>
#include <cstdio>
using namespace std;


typedef struct {
    struct {
        double x, y;
    } p1, p2;
} Rectangle;


void print(Rectangle r) {
    cout << r.p1.x << ends << r.p1.y << ends;
    cout << r.p2.x << ends << r.p2.y << endl;
}


Rectangle input() {
    Rectangle r;
    cin >> r.p1.x >> r.p1.y >> r.p2.x >> r.p2.y;
    return r;
}


int main() {
    Rectangle rect = {
        {1.0, 2.0},
        {3.0, 4.4}
    };
    print(rect);
    rect = input();
    print(rect);

    return 0;
}
