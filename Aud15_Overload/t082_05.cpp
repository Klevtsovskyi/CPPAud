#include <iostream>
#include <cmath>
#define N 100


using namespace std;


class Point
{
private:

    double x;
    double y;
    static int count;

public:

    Point(): Point(0, 0) {}

    Point(double x, double y): x(x), y(y)
    {
        count++;
        cout << "Point created!" << endl;
    }

    ~Point()
    {
        count--;
        cout << "Point deleted!" << endl;
    }

    static int get_count()
    {
        return count;
    }

    friend ostream& operator<<(ostream& out, Point* p)
    {
        out << "(" << p->x << ", " << p->y << ")";
        return out;
    }
};


int Point::count = 0;


class Polygon
{
private:

    static Point** points;

public:

    static void add_point(double x, double y)
    {
        points[Point::get_count() - 1] = new Point(x, y);
    }

};


Point** Polygon::points = new Point*[N];


int main()
{
    Polygon::add_point(1, 2);
    cout << Point::get_count() << endl;
    return 0;
}
