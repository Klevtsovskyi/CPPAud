#include <iostream>
#include <fstream>
#include <string>
using namespace std;


const int N = 100;


typedef struct {
    string name;
    int course;
    int group;
    int marks_count;
    int marks[N];
} Student;


void write(const char* filename, Student* students, int n) {
    ofstream fout(filename);
    if (!fout.good()) exit(1);

    for (int i = 0; i < n; i++) {
        fout << students[i].name << "; ";
        fout << "course: " << students[i].course << "; ";
        fout << "group: " << students[i].group << "; ";
        fout << "marks: ";
        int j;
        for (j = 0; j < students[i].marks_count - 1; j++) {
            fout << students[i].marks[j] << ", ";
        }
        fout << students[i].marks[j] << endl;
    }

    fout.close();
}


int read(const char* filename, Student* students) {
    ifstream finp(filename);
    if (!finp.good()) exit(1);
    int n = 0;
    while (finp.good()) {
        int x;
        string s;
        finp >> s;
        if (finp.fail()) {break;}
        s.pop_back();
        students[n].name = s;

        finp >> s >> x;
        students[n].course = x;

        finp.ignore(256, ';');
        finp >> s >> x;
        students[n].group = x;

        finp.ignore(256, ';');
        finp >> s;
        students[n].marks_count = 0;

        do {
            finp >> x;
            students[n].marks[students[n].marks_count] = x;
            students[n].marks_count++;
        } while (finp.get() == ',');
        n++;
    }

    finp.close();
    return n;
}


int main() {
    int n = 3;
    Student students[N] = {
        {"Alex", 1, 2, 3, {5, 4, 5}},
        {"John", 2, 2, 4, {4, 4, 4, 3}},
        {"Kate", 2, 1, 1, {5}}
    };
    write("output.txt", students, n);
    n = read("output.txt", students);
    cout << n << endl;
    return 0;
}
