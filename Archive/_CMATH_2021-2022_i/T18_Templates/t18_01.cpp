#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <exception>
#define N 100
using namespace std;


class RationalError: public logic_error {

public:
    RationalError(string message): logic_error(message) {}
};


class ZeroDenominatorError: public RationalError {

public:
    ZeroDenominatorError(): RationalError("Zero denominator!") {}
};


class NegativeDenominatorError: public RationalError {

public:
    NegativeDenominatorError(int64_t d):
        RationalError("Negative denominator! " + to_string(d)) {}
};


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
            throw ZeroDenominatorError();
        if (denom < 0)
            throw NegativeDenominatorError(denom);
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


template<class T>
T& min(T* arr, int n) {
    T& _min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < _min)
            _min = arr[i];
    }
    return _min;
}


int main() {
    srand(time(NULL));

    int n = 10;
    Rational arr1[N];
    for (int i = 0; i < n; i++) {
        arr1[i] = Rational("random");
        cout << arr1[i] << ends;
    }
    cout << endl;

    cout << min<Rational>(arr1, n) << endl;

    int arr2[N];
    for (int i = 0; i < n; i++) {
        arr2[i] = rand() % 100;
        cout << arr2[i] << ends;
    }
    cout << endl;

    cout << min<int>(arr2, n) << endl;

    return 0;
}
