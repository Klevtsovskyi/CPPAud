#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class ZeroDenominatorError: public exception
{
private:

    const char* message;

public:

    ZeroDenominatorError(const char* message="Zero denominator"):
        exception(), message(message) {}

    virtual const char* what() const throw()
    {
        return message;
    }
};


class Rational
{
private:

    int64_t numerator;
    uint64_t denominator;

    void to_irreducible()
    {
        uint64_t d = gcd((uint64_t) abs(numerator), denominator);
        numerator /= (int64_t) d;
        denominator /= d;
    }

public:

    Rational()
    {
        numerator = 0;
        denominator = 1;
        // cout << "Creating Rational "; print();
    }

    Rational(int64_t numerator, uint64_t denominator)
    {
        if (denominator == 0)
        {
            throw ZeroDenominatorError();
        }
        this->numerator = numerator;
        this->denominator = denominator;
        // cout << "Creating Rational "; print();
    }

    Rational(const Rational& a)
    {
        numerator = a.numerator;
        denominator = a.denominator;
        // cout << "Copying Rational "; print();
    }

    ~Rational()
    {
        // cout << "Deleting Rational "; print();
    }

    static uint64_t gcd(uint64_t a, uint64_t b)
    {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }

    void add(const Rational& other)
    {
        numerator = (numerator * other.denominator +
                     other.numerator * denominator);
        denominator = denominator * other.denominator;
        to_irreducible();
    }

    void product(const Rational& other)
    {
        numerator = numerator * other.numerator;
        denominator = denominator * other.denominator;
        to_irreducible();
    }

    Rational operator+(const Rational& other)
    {
        Rational result(*this);
        result.add(other);
        return result;
    }

    Rational operator+()
    {
        return Rational(numerator, denominator);
    }

    Rational operator-()
    {
        return Rational(-numerator, denominator);
    }

    Rational operator-(Rational& other)
    {
        Rational result(*this);
        result.add(-other);
        return result;
    }

    friend istream& operator>>(istream& inp, Rational& a)
    {
        inp >> a.numerator >> a.denominator;
        if (a.denominator == 0)
        {
            throw ZeroDenominatorError();
        }
        a.to_irreducible();
        return inp;
    }

    friend ostream& operator<<(ostream& out, const Rational& a)
    {
        out << a.numerator << "/" << a.denominator;
        return out;
    }

    bool operator<(const Rational& other)
    {
        // cout << "Calling '<' ";
        return (numerator * other.denominator <
                other.numerator * denominator);
    }

    bool operator<(const int other)
    {
        return (numerator < other * (int64_t) denominator);
    }

    bool operator>(Rational& other)
    {
        // cout << "Calling '>' ";
        return other < *this;
    }

    bool operator==(Rational& other)
    {
        if (numerator * other.denominator ==
            other.numerator * denominator)
            return true;
        else
            return false;
    }

    bool operator>=(Rational& other)
    {
        if (*this > other || *this == other)
            return true;
        else
            return false;
    }

    Rational operator*=(Rational& other)
    {
        product(other);
        return *this;
    }

    Rational operator+=(Rational& other)
    {
        add(other);
        return *this;
    }

    friend Rational abs(Rational& a)
    {
        return (a < 0) ? -a : a;
    }
};


template<class Number>
class Polynom
{
private:

    vector<Number> coefs;

public:

    Polynom(vector<Number>& coefs): coefs(coefs) {}
    Polynom() {}

    void input(int n)
    {
        for (int i = 0; i < n; i++)
        {
            Number num;
            cin >> num;
            coefs.push_back(num); // [1, 2, 3]
        }
        reverse(coefs.begin(), coefs.end()); // [3, 2, 1]
    }

    friend ostream& operator<<(ostream& out, const Polynom p)
    {
        for (int i = p.coefs.size() - 1; i > 0; i--)
            out << p.coefs[i] << "*x^" << i << " + ";
        out << p.coefs[0];
        return out;
    }

    static Polynom sum(Polynom& a, Polynom& b)
    {
        size_t m = max(a.coefs.size(), b.coefs.size());
        vector<Number> v(m);
        for (int i = 0; i < a.coefs.size(); i++)
            v[i] += a.coefs[i];
        for (int i = 0; i < b.coefs.size(); i++)
            v[i] += b.coefs[i];
        return Polynom(v);
    }
};


int main()
{
    Polynom<Rational> a, b, c;

    int n;
    cout << "Input n: "; cin >> n;
    cout << "Coefs: "; a.input(n);
    cout << a << endl;

    cout << "Input n: "; cin >> n;
    cout << "Coefs: "; b.input(n);
    cout << b << endl;

    c = c.sum(a, b);
    cout << "a + b: " << c << endl;

    return 0;
}
