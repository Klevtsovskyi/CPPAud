#include <iostream>


using namespace std;


class Rational
{
private:

    int numerator;
    unsigned denominator;

    void input_numerator()
    {
        cout << "input numerator: ";
        cin >> numerator;
    }

    void input_denominator()
    {
        while (true)
        {
            cout << "input denominator: ";
            cin >> denominator;
            if (denominator == 0)
                cerr << "Zero denominator! Enter again: ";
            else
                break;
        }
    }

    void to_irreducible()
    {
        unsigned d = gcd((unsigned) abs(numerator), denominator);
        numerator /= (int) d;
        denominator /= d;
    }

public:

    Rational()
    {
        numerator = 1;
        denominator = 1;
        cout << "Creating Rational ";
        print();
    }

    Rational(int numerator, unsigned denominator)
    {
        if (denominator == 0)
        {
            cerr << "Zero denominator!\n";
            throw;
        }
        this->numerator = numerator;
        this->denominator = denominator;
        cout << "Creating Rational ";
        print();
    }

    Rational(const Rational& a)
    {
        numerator = a.numerator;
        denominator = a.denominator;
        cout << "Copying Rational ";
        print();
    }

    ~Rational()
    {
        cout << "Deleting Rational ";
        print();
    }

    static unsigned gcd(unsigned a, unsigned b)
    {
        if (b == 0)
            return a;
        else
            return gcd(b, a % b);
    }

    void input()
    {
        //cout << "Input numerator/denominator: ";
        //cin >> numerator >> denominator;
        input_numerator();
        input_denominator();
        to_irreducible();
    }

    void print()
    {
        cout << numerator << "/" << denominator << endl;
    }

    void add(const Rational& other);
    void product(const Rational& other);
};


void Rational::add(const Rational& other)
{
    numerator = (numerator * other.denominator +
                 other.numerator * denominator);
    denominator = denominator * other.denominator;
    to_irreducible();
}


void Rational::product(const Rational& other)
{
    numerator = numerator * other.numerator;
    denominator = denominator * other.denominator;
    to_irreducible();
}


int main()
{
    Rational a, b;
    a.input();
    b.input();
    a.print();
    b.print();

    cout << "sum: ";
    a.add(b);
    a.print();

    cout << "product: ";
    a.product(b);
    a.print();

    Rational c{1, 4};
    c.print();

    Rational d(c);
    d.print();

    return 0;
}
