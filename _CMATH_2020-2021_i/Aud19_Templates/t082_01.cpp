#include <iostream>


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
        numerator = 1;
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


template <class T>
T get_max(T* array, int n)
{
    T max_item = array[0];
    for (int i = 0; i < n; i++)
    {
        if (array[i] > max_item)
            max_item = array[i];
    }
    return max_item;
}


int main()
{
    /*
    int const N = 6;
    int ints[N] = {1, 2, 0, -3, -4, 4};
    double doubles[N] = {1.2, 3.4, -2.3, 0.1, 3.1, 3.0};

    cout << get_max<int>(ints, N) << endl;
    cout << get_max<double>(doubles, N) << endl;
    */

    int n;
    cout << "Input count of Rationals: ";
    cin >> n;
    Rational* array = new Rational[n];
    for (int i = 0; i < n; i++)
    {
        while (true)
        {
            try
            {
                cout << "Input Rational: ";
                cin >> array[i];
                break;
            }
            catch (ZeroDenominatorError& e)
            {
                cout << e.what() << endl;
                cout << "Try again ";
            }
            catch (exception& e) {}
            catch (int& e) {}
            catch (...) {}
        }
    }
    cout << "Rationals: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << array[i] << endl;
    }
    cout << "Max: " << get_max<Rational>(array, n) << endl;

    delete[] array;

    return 0;
}
