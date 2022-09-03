#include <iostream>
#include <cmath>
#define N 100


using namespace std;








class Polygon
{
private:

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

        static double dis(Point* p1, Point* p2)
        {
            return sqrt(pow(p2->x - p1->x, 2) +
                        pow(p2->y - p1->y, 2));
        }
    };

    static Point** points;

public:

    static void add_point(double x, double y)
    {
        points[Point::get_count() - 1] = new Point(x, y);
    }

    static void print()
    {
        for (int i = 0; i < Point::get_count(); i++)
            cout << points[i] << endl;
        cout << "Count of points: " << Point::get_count() << endl;
    }

    static void free()
    {
        while (Point::get_count() > 0)
        {
            delete points[Point::get_count() - 1];
        }
        delete[] points;
        cout << "Polygon deleted!" << endl;
    }

    static double perimeter()
    {
        double result = 0;
        for (int i = 1; i < Point::get_count(); i++)
        {
            result += Point::dis(points[i-1], points[i]);
        }
        result += Point::dis(points[Point::get_count() - 1],
                             points[0]);
        return result;
    }

};


int Polygon::Point::count = 0;
Polygon::Point** Polygon::points = new Point*[N];


int main()
{
    // Polygon::add_point(1, 2);
    // cout << Point::get_count() << endl;
    double x, y;
    while (true)
    {
        cin >> x >> y;
        if (cin.fail())
            break;
        Polygon::add_point(x, y);
    }
    Polygon::print();
    cout << "Perimeter: " << Polygon::perimeter() << endl;
    Polygon::free();
    return 0;
}
