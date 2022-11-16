#include <iostream>
#define DEBUG 0
#define N 100
using namespace std;


class Human {

protected:

    string name;

public:

    Human(const string& name): name(name) {
        if (DEBUG) cout << "Create Human " << name << endl;
    }
    virtual ~Human() {
        if (DEBUG) cout << "Delete Human " << name << endl;
    }

    virtual void print() {
        cout << name;
    }
    void hello() {
        cout << "Hello from ";
        print();
        cout << endl;
    }
};


class Student: virtual public Human {

protected:

    int course;
    string univ;

public:

    Student(const string& name, int course, const string& univ):
        Human(name), course(course), univ(univ) {

        if (DEBUG) cout << "Create Student " << name << endl;
    }
    virtual ~Student() {
        if (DEBUG) cout << "Delete Student " << name << endl;
    }

    virtual void print() {
        Human::print();
        cout << ' ' << univ << ' ' << course;
    }
};


class Teacher: virtual public Human {

protected:

    double salary;
    string univ;

public:

    Teacher(const string& name, double salary, const string& univ):
        Human(name), salary(salary), univ(univ) {

        if (DEBUG) cout << "Create Teacher " << name << endl;
    }
    virtual ~Teacher() {
        if (DEBUG) cout << "Delete Teacher " << name << endl;
    }

    virtual void print() {
        Human::print();
        cout << ' ' << univ << ' ' << salary;
    }
};


class PGS: public Student, public Teacher {

public:

    PGS(
        const string& name,
        int course,
        double salary,
        const string univ
    ):
        Human(name),
        Student(name, course, univ),
        Teacher(name, salary, univ) {

        if (DEBUG) cout << "Create PGS " << name << endl;
    }
    virtual ~PGS() {
        if (DEBUG) cout << "Delete PGS " << name << endl;
    }

    virtual void print() {
        Human::print();
        cout << ' ' << Student::univ << ' ';
        cout << Teacher::univ << ' ';
        cout << course << ' ' << salary;
    }
};


int main() {
    int n = 4;
    Human* arr[N] = {
        new Human("John"),
        new Student("Kate", 1, "NPU"),
        new Teacher("Ben", 1000.1, "KPI"),
        new PGS("Alex", 2, 1100.1, "KNU")
    };

    for (int i = 0; i < n; i++) {
        arr[i]->hello();
    }
    for (int i = 0; i< n; i++) {
        delete arr[i];
    }
    return 0;
}
