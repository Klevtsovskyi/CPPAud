#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <sstream>
using namespace std;


class Person {

    string name;
    unsigned byear;

public:

    Person(const string& _name, unsigned _byear): name(_name), byear(_byear) {}

    string get_name() const {return name;}
    void set_name(const string& name) {this->name = name;}
    unsigned get_byear() const {return byear;}
    void set_byear(unsigned byear) {this->byear = byear;}

    virtual void input(istream& inp = cin) {
        inp >> name >> byear;
    }

    virtual void print(ostream& out = cout) const {
        out << name << ' ' << byear;
    }

    friend ostream& operator<<(ostream& out, const Person& p) {
        p.print(out);
        return out;
    }

    friend istream& operator>>(istream& inp, Person& p) {
        p.input(inp);
        return inp;
    }
};


class Friend: public Person {

    string phone;

public:

    Friend(
        const string& _name = "",
        unsigned _byear = 0,
        const string& _phone = ""
    ):
        Person(_name, _byear), phone(_phone) {}

    string get_phone() const {return phone;}
    void set_phone(const string& phone) {this->phone = phone;}

    virtual void input(istream& inp = cin) {
        Person::input(inp);
        inp >> phone;
    }

    virtual void print(ostream& out = cout) const {
        Person::print(out);
        out << ' ' << phone;
    }
};


class PhoneBook {

    string filename;

public:

    PhoneBook(const string& filename): filename(filename) {}

    void create() {
        ofstream fout(filename);
        if (fout.bad()) throw logic_error("");
        fout.close();
    }

    void add_friend(const Friend& f) {
        ofstream fout(filename, ofstream::app);
        if (fout.bad()) throw logic_error("");
        fout << f << endl;
        fout.close();
    }

    string find_phone(const string& name) {
        ifstream finp(filename);
        if (finp.bad()) throw logic_error("");

        Friend f;
        while (finp.good()) {
            finp >> f;
            if (finp.fail()) {
                throw logic_error("Cannot find friend " + name);
            }
            if (f.get_name() == name) {
                break;
            }
        }
        finp.close();
        return f.get_phone();
    }

    void change_phone(const string& name, const string& new_phone) {
        ifstream finp(filename);
        if (finp.bad()) throw logic_error("");

        ostringstream oss;
        while (finp.good()) {
            Friend f;
            finp >> f;
            if (finp.fail()) {
                break;
            }
            if (f.get_name() == name) {
                f.set_phone(new_phone);
            }
            oss << f << endl;
        }
        finp.close();

        ofstream fout(filename);
        if (finp.bad()) throw logic_error("");
        fout << oss.str();
        fout.close();
    }
};


int main() {
    Friend f1("Alex", 2005, "333-333-33-33");
    Friend f2("John", 2006, "444-444-44-44");
    Friend f3("Kate", 2007, "555-555-55-55");

    PhoneBook book("friends.txt");
    book.create();
    book.add_friend(f1);
    book.add_friend(f2);
    book.add_friend(f3);

    book.change_phone("John", "777-777-77-77");
    cout << "John " << book.find_phone("John") << endl;

    return 0;
}
