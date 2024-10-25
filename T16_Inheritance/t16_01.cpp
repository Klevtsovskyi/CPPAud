#include <iostream>
#include <istream>
#include <ostream>
using namespace std;


class Person {

private:
    string _name;
    unsigned _byear;

public:

    Person(string name, unsigned byear): _name(name), _byear(byear) {};

    string getName() {return _name;}
    void setName(string name) {_name = name;}
    unsigned getYear() {return _byear;}
    void setYear(unsigned byear) {_byear = byear;}

    void input(istream& inp = cin) {
        inp >> _name >> _byear;
    }
    void print(ostream& out = cout) const {
        out << _name << ' ' << _byear;
    }
    friend istream& operator >> (istream& inp, Person& p) {
        p.input(inp);
        return inp;
    }
    friend ostream& operator << (ostream& out, const Person& p) {
        p.print(out);
        return out;
    }
};


class Friend: public Person {

private:
    string _phone;

public:
    Friend(string name, unsigned byear, string phone):
        Person(name, byear), _phone(phone) {};

    string getPhone() {return _phone;}
    void setPhone(string phone) {_phone = phone;}

    void input(istream& inp = cin) {
        Person::input(inp);
        inp >> _phone;
    }
    void print(ostream& out = cout) const {
        Person::print(out);
        out << ' ' << _phone;
    }
};


int main() {

    return 0;
}
