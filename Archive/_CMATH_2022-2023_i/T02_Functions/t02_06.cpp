#include <cstdio>
#include <cmath>


double distance(double x1, double y1, double x2, double y2) {
    return hypot(x2 - x1, y2 - y1);
}


double square(double a, double b, double c) {
    double p = (a + b + c) / 2;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}


int main() {
    double x1, y1, x2, y2, x3, y3, a, b, c, s;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    a = distance(x1, y1, x2, y2);
    b = distance(x2, y2, x3, y3);
    c = distance(x3, y3, x1, y1);
    printf("%lf %lf %lf\n", a, b, c);
    s = square(a, b, c);
    printf("%lf\n", s);
    return 0;
}
