#include <iostream>
#include <ostream>
#include <istream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;


class Rational {

private:

    int64_t numer;
    int64_t denom;

    void to_irreducible() {
        int64_t d = gcd(abs(numer), denom);
        numer /= d;
        denom /= d;
    }

    void init(int64_t numer, int64_t denom) {
        if (denom == 0)
            throw logic_error("Zero denominator!");
        if (denom < 0)
            throw logic_error("Negative denominator " + to_string(denom));
        this->numer = numer;
        this->denom = denom;
        to_irreducible();
    }

public:

    Rational(int64_t numer, int64_t denom) {init(numer, denom);}
    Rational(): Rational(1, 1) {}
    Rational(int64_t number): Rational(number, 1) {}
    Rational(const Rational& r): Rational(r.numer, r.denom) {}
    Rational(const string& s) {
        init(rand() % 200 - 100, rand() % 100 + 1);
    }

    void print(ostream& out = cout) const {
        out << numer << '/' << denom;
    }

    void input(istream& inp = cin) {
        int64_t n, d;
        inp >> n;
        inp.ignore(256, '/');
        inp >> d;
        init(n, d);
    }

    void add(const Rational& other) {
        numer = numer * other.denom + other.numer * denom;
        denom = denom * other.denom;
        to_irreducible();
    }

    void multiply(const Rational& other) {
        numer = numer * other.numer;
        denom = denom * other.denom;
        to_irreducible();
    }

    Rational operator+() const {return Rational(*this);}
    Rational operator-() const {return Rational(-numer, denom);}

    Rational operator+(const Rational& other) const {
        Rational result(*this);
        result.add(other);
        return result;
    }

    friend Rational operator+(const Rational& self, int64_t other) {
        Rational result(self);
        result.add(Rational(other));
        return result;
    }

    Rational operator-(const Rational& other) const {
        Rational result(*this);
        result.add(-other);
        return result;
    }

    Rational operator*(const Rational& other) const {
        Rational result(*this);
        result.multiply(other);
        return result;
    }

    Rational& operator+=(const Rational& other) {add(other); return *this;}
    Rational& operator*=(const Rational& other) {multiply(other); return *this;}

    bool operator<(const Rational& other) const {return numer * other.denom < other.numer * denom;}
    bool operator<(int64_t x) const {return numer < x * denom;}
    bool operator>(const Rational& other) const {return numer * other.denom > other.numer * denom;}
    bool operator>(int64_t x) const {return numer > x * denom;}
    bool operator<=(const Rational& other) const {return numer * other.denom <= other.numer * denom;}
    bool operator>=(const Rational& other) const {return numer * other.denom >= other.numer * denom;}
    bool operator==(const Rational& other) const {return numer == other.numer && denom == other.denom;}
    bool operator!=(const Rational& other) const {return numer != other.numer || denom != other.denom;}

    double to_double() {return (double) numer / denom;}

    static int64_t gcd(int64_t a, int64_t b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    static int64_t abs(int64_t x) {
        return (x < 0) ? -x : x;
    }

    static Rational abs(const Rational& r) {
        return (r < 0) ? Rational(-r) : Rational(r);
    }

    friend ostream& operator<<(ostream& out, const Rational& r) {
        r.print(out);
        return out;
    }

    friend istream& operator>>(istream& inp, Rational& r) {
        r.input(inp);
        return inp;
    }

};


Rational min(Rational* arr, int n) {
    Rational result = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < result) {
            result = arr[i];
        }
    }
    return result;
}


double pi(const Rational& eps = Rational(1, 100)) {
    Rational s(1);
    Rational a(1);
    int i = 1;
    while (Rational::abs(a) > eps) {
        i++;
        a = Rational((i % 2 == 0) ? -1 : 1, i * i);
        s += a;
    }
    s *= Rational(12);
    return sqrt(s.to_double());
}


int main() {
    srand(time(nullptr));

    int n = 5;
    Rational* arr = new Rational[n];
    for (int i = 0; i < n; i++) {
        arr[i] = Rational("random");
        cout << arr[i] << endl;
    }
    cout << "Min: " << min(arr, n) << endl;
    cout << "Pi: " << pi(Rational(1, 100)) << endl;

    delete[] arr;
    return 0;
}
