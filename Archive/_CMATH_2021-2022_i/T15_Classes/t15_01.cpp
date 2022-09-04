#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
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

    void initialize(int64_t numer, int64_t denom) {
        if (denom == 0)
            throw logic_error("Zero denominator!");
        if (denom < 0)
            throw logic_error("Negative denominator! " + to_string(denom));
        this->numer = numer;
        this->denom = denom;
        to_irreducible();
    }

public:

    Rational(int64_t numer, int64_t denom) {
        initialize(numer, denom);
    }

    Rational(): Rational(1, 1) {}
    Rational(int64_t number): Rational(number, 1) {}
    Rational(const Rational& a): Rational(a.numer, a.denom) {}

    Rational(const string& random) {
        int sign = rand() % 2 ? 1 : -1;
        initialize(sign * rand() % 100, rand() % 100 + 1);
    }

    void print(ostream& out = cout) {
        out << numer << "/" << denom;
    }

    void input(istream& inp = cin) {
        int64_t numer, denom;
        inp >> numer;
        inp.ignore(256, '/');
        inp >> denom;
        initialize(numer, denom);
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

    Rational operator+() {return Rational(*this);}
    friend Rational operator-(const Rational& self) {return Rational(-self.numer, self.denom);}

    Rational operator+(const Rational& other) {
        Rational result(*this);
        result.add(other);
        return result;
    }

    Rational operator-(const Rational& other) {
        Rational result(*this);
        result.add(-other);
        return result;
    }

    Rational operator*(const Rational& other) {
        Rational result(*this);
        result.multiply(other);
        return result;
    }

    Rational& operator+=(const Rational& other) {add(other); return *this;}
    Rational& operator-=(const Rational& other) {add(-other); return *this;}
    Rational& operator*=(const Rational& other) {multiply(other); return *this;}

    bool operator<(const Rational& other) {return numer * other.denom < other.numer * denom;}
    bool operator<(const int other) {return numer < denom * other;}
    bool operator>(const Rational& other) {return numer * other.denom > other.numer * denom;}
    bool operator>(const int other) {return numer > denom * other;}
    bool operator<=(const Rational& other) {return numer * other.denom <= other.numer * denom;}
    bool operator>=(const Rational& other) {return numer * other.denom >= other.numer * denom;}
    bool operator==(const Rational& other) {return numer == other.numer && denom == other.denom;}
    bool operator!=(const Rational& other) {return numer != other.numer || denom != other.denom;}

    double to_double() {return (double) numer / denom;}

    static int64_t gcd(int64_t a, int64_t b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    static int64_t abs(int64_t a) {
        return a > 0 ? a : -a;
    }

    friend Rational abs(Rational& a) {
        return a > 0 ? +a : -a;
    }

    friend ostream& operator<<(ostream& out, Rational& a) {
        a.print(out);
        return out;
    }

    friend istream& operator>>(istream& inp, Rational& a) {
        a.input(inp);
        return inp;
    }

};


Rational& min(Rational* arr, int n) {
    Rational& _min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < _min)
            _min = arr[i];
    }
    return _min;
}


double pi(const Rational& eps) {
    Rational s(1);
    Rational a(1);
    int i = 1;
    while (abs(a) > eps) {
        i++;
        a = Rational(i % 2 ? 1 : -1) * Rational(1, i * i);
        s += a;
    }
    s *= Rational(12);
    return sqrt(s.to_double());
}


double pi(double eps) {
    double s = 1.0;
    double a = 1.0;
    int i = 1;
    while (abs(a) > eps) {
        i++;
        a = (i % 2 ? 1.0 : -1.0) / i / i;
        s += a;
    }
    return sqrt(s * 12.0);
}


int main() {
    srand(time(NULL));

    int n = 5;
    Rational* arr = new Rational[n];
    for (int i = 0; i < n; i++) {
        arr[i] = Rational(string(""));
        cout << arr[i] << ends;
    }
    cout << endl;

    cout << min(arr, n) << endl << endl;

    Rational eps(1, 100);
    cout << pi(eps) << endl;
    cout << pi(0.01) << endl;

    delete[] arr;
    return 0;
}
