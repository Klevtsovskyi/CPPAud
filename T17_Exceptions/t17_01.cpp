#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;


class RationalError: public logic_error {
public:
    RationalError(const char* msg): logic_error(msg) {};
};


class Rational {

private:

    long long numer;
    long long denom;

    void init(long long n, long long d) {
        if (d <= 0)
            throw RationalError("Zero or negative denominator!");
        numer = n;
        denom = d;
        reduce();
    }

    void reduce() {
        long long d = gcd(abs(numer), denom);
        numer /= d;
        denom /= d;
    }

public:

    Rational(long long numer, long long denom) {init(numer, denom);}
    Rational(): numer(1), denom(1) {}
    Rational(long long numer): numer(numer), denom(1) {}
    Rational(const Rational& r): Rational(r.numer, r.denom) {}

    static Rational random() {
        long long n = rand() % 200 - 100;
        long long d = rand() % 100 + 1;
        return Rational(n, d);
    }

    void print(ostream& out = cout) const {
        out << numer << '/' << denom;
    }

    void input(istream& inp = cin) {
        long long n, d;
        inp >> n;
        inp.ignore(256, '/');
        inp >> d;
        init(n, d);
    }

    void add(const Rational& other) {
        numer = numer * other.denom + other.numer * denom;
        denom = denom * other.denom;
        reduce();
    }
    void multiply(const Rational& other) {
        numer *= other.numer;
        denom *= other.denom;
        reduce();
    }

    Rational operator+ () const {return Rational(*this);}
    Rational operator- () const {return Rational(-numer, denom);}

    bool operator< (const Rational& other) const {return numer * other.denom < other.numer * denom;}
    bool operator< (double x) const {return (double) numer < x * denom;}
    bool operator> (const Rational& other) const {return numer * other.denom > other.numer * denom;}
    bool operator> (double x) const {return (double) numer > x * denom;}
    bool operator<= (const Rational& other) const {return numer * other.denom <= other.numer * denom;}
    bool operator>= (const Rational& other) const {return numer * other.denom >= other.numer * denom;}
    bool operator== (const Rational& other) const {return numer == other.numer && denom == other.denom;}
    bool operator!= (const Rational& other) const {return numer != other.numer || denom != other.denom;}

    Rational& operator+= (const Rational& other) {add(other); return *this;}

    Rational operator+ (const Rational& other) const {
        Rational result(*this);
        result.add(other);
        return result;
    }
    friend Rational operator- (const Rational& self, const Rational& other) {
        Rational result(self);
        result.add(-other);
        return result;
    }
    Rational operator*(const Rational& other) const {
        Rational result(*this);
        result.multiply(other);
        return result;
    }

    double to_double() {return (double) numer / denom;}

    static long long abs(long long x)  {
        return (x < 0) ? -x : x;
    }

    static Rational abs(const Rational& r) {
        return (r < 0) ? Rational(-r) : Rational(r);
    }

    static long long gcd(long long a, long long b) {
        while (b > 0) {
            long long tmp = a % b;
            a = b;
            b = tmp;
        }
        return a;
    }

    friend ostream& operator<< (ostream& out, const Rational& r) {
        r.print(out);
        return out;
    }

    friend istream& operator>> (istream& inp, Rational& r) {
        r.input(inp);
        return inp;
    }

};


double pi(double eps=0.01) {
    Rational s(1), a(1);
    long long i = 1;
    while (Rational::abs(a) > eps) {
        i++;
        a = Rational(i % 2 ? 1 : -1, i * i);
        s += a;
    }
    return sqrt(12.0 * s.to_double());
}


int main() {
    int n;
    cin >> n;

    Rational* array = new Rational[n];

    for (int i = 0; i < n; i++) {
        try {
            cin >> array[i];
        }
        catch (RationalError& e) {
            cout << e.what() << endl;
        }
        catch (exception& e) {
            cerr << e.what() << endl;
            break;
        }
        catch (...) {
            cerr << "Unknown exception was caught" << endl;
            break;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << array[i] << ' ';
    }

    delete[] array;
    return 0;
}
