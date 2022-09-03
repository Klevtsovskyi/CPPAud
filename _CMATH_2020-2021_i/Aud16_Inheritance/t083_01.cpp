#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;


class Person
{
private:

    string name;
    unsigned byear;

public:

    Person(string name="PERSON",
           unsigned byear=1900):
               name(name), byear(byear) {}

    int read(istream& inp)
    {
        inp >> name >> byear;
        if (inp.fail()) return 0;
        else return 1;
    }

    void print(ostream& out, bool endline=true)
    {
        out << name << ' ' << byear;
        if (endline) out << endl;
    }

    string get_name() {return name;}
    void set_name(string n) {name = n;}
    unsigned get_byear() {return byear;}
    void set_byear(unsigned b) {byear = b;}

    Person operator+() {return Person(*this);}
};


class Friend: public Person
{
private:

    string phone;

public:

    Friend(string name="FRIEND",
           unsigned byear=1901,
           string phone="888-888-88-88"):
               Person(name, byear), phone(phone) {}

    Friend(Person p): Person(p), phone("999-999-99-99") {}

    int read(istream& inp)
    {
        int rez = Person::read(inp);
        inp >> phone;
        if (inp.fail()) return 0;
        else return rez;
    }

    void print(ostream& out, bool endline=true)
    {
        Person::print(out, false);
        out << ' ' << phone;
        if (endline) out << endl;
    }

    string get_phone() {return phone;}
    void set_phone(string p) {phone = p;}
};


class PhoneBook
{
private:

    string filename;

public:

    PhoneBook(string filename): filename(filename) {}

    void create()
    {
        ofstream fout;
        fout.open(filename);
        fout.close();
    }

    void add_friend(Friend& f)
    {
        ofstream fout;
        fout.open(filename, ios_base::app);
        f.print(fout);
        fout.close();
    }

    Friend find_friend(string name)
    {
        ifstream finp;
        finp.open(filename);
        Friend f;
        while (f.read(finp))
        {
            if (f.get_name() == name)
                break;
        }
        finp.close();
        return f;
    }

    void change_phone(string name, string phone)
    {
        stringstream ss;
        ifstream finp;
        ofstream fout;
        finp.open(filename);
        Friend f;
        while (f.read(finp))
        {
            if (f.get_name() == name)
                f.set_phone(phone);
            f.print(ss);
        }
        finp.close();

        fout.open(filename);
        fout << ss.str();
        fout.close();
    }

};


int main()
{
    Person p("PPP");
    //p.print(cout);
    Friend a, b("BBB", 2001), c;
    c.set_name("CCC");
    c.set_byear(2002);
    c.set_phone("111-111-11-11");
    //c.print(cout);

    PhoneBook pb("t083_01.txt");
    pb.create();
    pb.add_friend(a);
    pb.add_friend(b);
    pb.add_friend(c);
    Friend d = pb.find_friend("BBB");
    d.set_name("DDD");
    pb.add_friend(d);
    pb.change_phone("BBB", "444-444-44-44");

    p = a;
    p.print(cout);
    (+p).print(cout);
    (+a).print(cout);
    Friend e(p);
    e.print(cout);
    return 0;
}
