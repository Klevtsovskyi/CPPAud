#include <iostream>
#include <cstdio>
using namespace std;


/*
// C++
struct Date {
    int day;
    int month;
    int year;
};
*/


typedef struct {
    int day;
    int month;
    int year;
    void* ptr;
} Date;


void print(Date a) {
    cout << a.day << ends << a.month << ends << a.year << endl;
}


Date input() {
    Date a;
    cin >> a.day >> a.month >> a.year;
    return a;
}


int main() {
    Date d = {2, 3, 2021};
    print(d);
    d.day = 1;
    d.month = 2;
    d.year = 2020;
    d.ptr = &d;
    print(d);
    Date c = {.day = 4, .month = 12, .year = 2022};
    print(c);
    Date b = input();
    print(b);
    // cout << sizeof d << endl;
    // cout << d.ptr << ends << (*((Date*) d.ptr)).ptr << endl;
    return 0;
}
