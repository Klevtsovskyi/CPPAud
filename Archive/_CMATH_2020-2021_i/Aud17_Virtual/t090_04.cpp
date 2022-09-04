#include <iostream>


using namespace std;


class Human
{
protected:

    string name;
    char sex;
    int age;

public:

    Human(string name, char sex='m', int age=20):
        name(name), sex(sex), age(age) {}

    virtual ~Human() {}

    virtual void print(bool endline=true)
    {
        cout << name << ' ' << sex << ' ' << age;
        if (endline) cout << endl;
    }

    virtual Human operator+()
    {
        return Human(*this);
    }

    // For abstract class
    // virtual void hello() = 0;
};


class Student: virtual public Human
{
protected:

    int course;
    int group;
    string university;

public:

    Student(string name, char sex='m', int age=20,
            int course=1, int group=1, string university="NUK"):
                Human(name, sex, age),
                course(course),
                group(group),
                university(university) {}

    Student(Human h):
        Human(h), course(2), group(2), university("K") {}

    virtual ~Student() {}

    virtual void print(bool endline=true)
    {
        cout << name << ' ' << sex << ' ' << age << ' ' <<
        course << ' ' << group << ' ' << university;
        if (endline) cout << endl;
    }

    virtual Human operator+()
    {
        return Student(*this);
    }
};


class Teacher: virtual public Human
{
protected:

    string position;
    double salary;
    string university;

public:

    Teacher(string name, char sex='m', int age=20,
            string position="professor", double salary=100.0,
            string university="NUK"):
                Human(name, sex, age),
                position(position),
                salary(salary),
                university(university) {}

    virtual ~Teacher() {}

    virtual void print(bool endline=true)
    {
        Human::print(false);
        cout << ' ' << position << ' ' << salary << ' ' <<
        university;
        if (endline) cout << endl;
    }
};


class PostGraduateStudent:
    public Student,
    public Teacher
{
public:

    PostGraduateStudent(string name, char sex='m', int age=20,
            int course=1, int group=1,
            string position="professor",
            double salary=100.0,
            string university="NUK"):
            Human(name, sex, age),
            Student(name, sex, age, course, group, university),
            Teacher(name, sex, age, position, salary, university)
    {}

    virtual ~PostGraduateStudent() {}

    virtual void print(bool endline=true)
    {
        Human::print(false);
        cout << ' ' << course << ' ' << group << ' ' <<
        position << ' ' << salary;
        cout << ' ' << Student::university;
        cout << ' ' << Teacher::university;
        cout << ' ' << &(Student::university);
        cout << ' ' << &(Teacher::university);
        if (endline) cout << endl;
    }
};


int main()
{
    Human *h, *s, *t, *p;
    h = new Human("Human"); h->print();
    s = new Student("Student"); s->print();
    t = new Teacher("Teacher"); t->print();
    p = new PostGraduateStudent("PGS"); p->print();

    (+*h).print();
    ((Student) +*s).print();

    delete h;
    delete s;
    delete t;
    delete p;
    return 0;
}
