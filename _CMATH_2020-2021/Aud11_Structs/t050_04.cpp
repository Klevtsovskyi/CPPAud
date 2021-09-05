#include <iostream>
#include <cmath>


using namespace std;


typedef enum {cart, polar} coord_type;


typedef struct
{
    coord_type coord;
    union
    {
       struct {double x, y;} c;
       struct {double ro, phi;} p;
    } t;
} Point;


Point point(coord_type ct, double x, double y)
{
    Point p = {.coord = ct};
    if (ct == cart)
    {
        p.t.c.x = x;
        p.t.c.y = y;
    }
    else if (ct == polar)
    {
        p.t.p.ro = x;
        p.t.p.phi = y;
    }
    return p;
}


double dis(Point p1, Point p2)
{
    if (p1.coord == polar)
        p1 = point(cart, p1.t.p.ro * cos(p1.t.p.phi),
                         p1.t.p.ro * sin(p1.t.p.phi));
    if (p2.coord == polar)
        p2 = point(cart, p2.t.p.ro * cos(p2.t.p.phi),
                         p2.t.p.ro * sin(p2.t.p.phi));
    return sqrt(pow(p2.t.c.x - p1.t.c.x, 2) +
                pow(p2.t.c.y - p1.t.c.y, 2));
}


double square(Point p1, Point p2, Point p3)
{
    double a, b, c, p;
    a = dis(p1, p2);
    b = dis(p2, p3);
    c = dis(p3, p1);
    p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}


int main()
{
    Point A = {A.coord = cart,
               A.t.c.x = 0,
               A.t.c.y = 0};
    Point B = point(polar, 1, M_PI/2);
    Point C = point(polar, 1, 0);

    cout << square(A, B, C) << endl;
    return 0;
}
