#include <iostream>
#include <istream>
#include <ostream>
#include <fstream>
using namespace std;


class Person {

private:
    string _name;
    unsigned _byear;

public:

    Person(string name = "", unsigned byear = 2000): _name(name), _byear(byear) {};
    // virtual ~Person() {cout << "Person deleted" << endl;};

    string getName() {return _name;}
    void setName(string name) {_name = name;}
    unsigned getYear() {return _byear;}
    void setYear(unsigned byear) {_byear = byear;}

    virtual void input(istream& inp = cin) {
        inp >> _name >> _byear;
    }
    virtual void print(ostream& out = cout) const {
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
    Friend(string name = "", unsigned byear = 0, string phone = "0001112233"):
        Person(name, byear), _phone(phone) {};

    // virtual ~Friend() {cout << "Friend deleted" << endl;};

    string getPhone() {return _phone;}
    void setPhone(string phone) {_phone = phone;}

    virtual void input(istream& inp = cin) {
        Person::input(inp);
        inp >> _phone;
    }
    virtual void print(ostream& out = cout) const {
        Person::print(out);
        out << ' ' << _phone;
    }
};


class PhoneBook {
private:
    Friend* book;
    int count;

public:
    PhoneBook() {
        book = new Friend[100];
    };
    ~PhoneBook() {
        delete[] book;
    };
    void read(const char* filename) {
        ifstream f(filename);
        if (!f.is_open())
            throw logic_error("Cannot find file");
        count = 0;
        while (f.good()) {
            f >> book[count++];
            if (f.fail())
                break;
        }
        f.close();
    }

    void write(const char* filename) {
        ofstream f(filename);
        if (!f.is_open())
            throw logic_error("Cannot open file");
        for (int i = 0 ; i < count; i++)
            f << book[i] << endl;
        f.close();
    }

    void append(Friend f) {
        book[count++] = f;
    }

    string search(const string& name) {
        for (int i = 0; i < count; i++) {
            if (book[i].getName() == name)
                return book[i].getPhone();
        }
        return "";
    }

    friend ostream& operator << (ostream& out, const PhoneBook& pb) {
        for (int i = 0; i < pb.count; i++) {
            out << pb.book[i] << endl;
        }
        return out;
    }
};


int main() {
    PhoneBook phoneBook;
    phoneBook.read("friends.txt");
    // cout << phoneBook;
    phoneBook.append(Friend("Polina", 2005, "0954119453"));
    cout << phoneBook.search("Polina") << endl;
    phoneBook.write("friends.txt");

    return 0;
}
