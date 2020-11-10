#include <iostream>


using namespace std;


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
        numerator = 1;
        denominator = 1;
        // cout << "Creating Rational "; print();
    }

    Rational(int64_t numerator, uint64_t denominator)
    {
        if (denominator == 0)
        {
            cerr << "Zero denominator!\n";
            throw;
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
            cerr << "Zero denominator!";
            throw;
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

    static Rational max_abs(Rational* array, int n)
    {
        Rational max_r(array[0]);
        for (int i = 0; i < n; i++)
        {
            Rational curr = abs(array[i]);
            if (curr > max_r)
                max_r = curr;
        }
        return max_r;
    }

    double to_double()
    {
        return (double) numerator / denominator;
    }
};


double gregori(int n)
{
    Rational result, a, b;
    for (int i = 1; i < n; i++)
    {
        b = Rational(-1 * (2*i - 1), (2*i + 1));
        a *= b;
        result += a;
    }
    return result.to_double();
}


int main()
{
    /*
    Rational a(-1, 3), b(7, 8);
    cout << "a: "; a.print();
    cout << "b: "; b.print();

    Rational c = a + b;
    cout << "c = a + b: "; c.print();

    cout << "+c: "; (+c).print();
    cout << "-c: "; (-c).print();

    cout << "a - b: "; (a - b).print();

    cout << "a < a: " << (a < a) << endl;
    cout << "a > a: " << (a > a) << endl;

    Rational d = abs(a);
    cout << "abs(a): " << d << endl;
    */


    const int N = 3;
    Rational array[N] = {Rational(1, 2),
                         Rational(-1, 3),
                         Rational(-3, 5)};
    cout << "max: " << Rational::max_abs(array, 3) << endl;

    int n = 20;
    cout << "Gregori for " << n << ": " << gregori(n) << endl;
    return 0;
}
