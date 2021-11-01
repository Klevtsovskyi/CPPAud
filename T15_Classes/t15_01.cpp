#include <iostream>
#include <string>
using namespace std;


class Rational {

private:

    int64_t nomin;
    int64_t denom;

    void to_irreducible() {
        int64_t d = gcd(abs(nomin), denom);
        nomin /= d;
        denom /= d;
    }

    void initialize(int64_t nomin, int64_t denom) {
        if (denom == 0)
            throw logic_error("Zero denominator!");
        if (denom < 0)
            throw logic_error("Negative denominator! " + to_string(denom));
        this->nomin = nomin;
        this->denom = denom;
        to_irreducible();
    }

public:

    Rational(int64_t nomin, int64_t denom) {
        initialize(nomin, denom);
    }

    Rational(): Rational(1, 1) {}
    Rational(int64_t number): Rational(number, 1) {}
    Rational(const Rational& a): Rational(a.nomin, a.denom) {}

    void print() {
        cout << nomin << "/" << denom << endl;
    }

    void input() {
        int64_t nomin, denom;
        cin >> nomin;
        cin.ignore(256, '/');
        cin >> denom;
        initialize(nomin, denom);
    }

    void add(const Rational& other) {
        nomin = nomin * other.denom + other.nomin * denom;
        denom = denom * other.denom;
        to_irreducible();
    }

    void multiply(const Rational& other) {
        nomin = nomin * other.nomin;
        denom = denom * other.denom;
        to_irreducible();
    }

    Rational operator+() {return Rational(*this);}
    Rational operator-() {return Rational(-nomin, denom);}

    Rational operator+(const Rational& other) {
        Rational result(*this);
        result.add(other);
        return result;
    }

    Rational operator-(Rational& other) {
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
    Rational& operator-=(Rational& other) {add(-other); return *this;}
    Rational& operator*=(const Rational& other) {multiply(other); return *this;}

    bool operator<(const Rational& other) {return nomin * other.denom < other.nomin * denom;}
    bool operator>(const Rational& other) {return nomin * other.denom > other.nomin * denom;}
    bool operator<=(const Rational& other) {return nomin * other.denom <= other.nomin * denom;}
    bool operator>=(const Rational& other) {return nomin * other.denom >= other.nomin * denom;}
    bool operator==(const Rational& other) {return nomin == other.nomin && denom == other.denom;}
    bool operator!=(const Rational& other) {return nomin != other.nomin || denom != other.denom;}

    static int64_t gcd(int64_t a, int64_t b) {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    static int64_t abs(int64_t a) {
        return a > 0 ? a : -a;
    }

};


int main() {
    Rational a;
    Rational b;

    a.input();
    b.input();

    cout << boolalpha;
    cout << (a != b) << endl;

    return 0;
}
