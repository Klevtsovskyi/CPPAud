#include <iostream>
#include <cstdio>
using namespace std;


/* C++
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
} Date;


void print(Date date) {
    printf("%02ld.%02ld.%ld\n", date.day, date.month, date.year);
}


Date input() {
    Date date;
    scanf("%ld.%ld.%ld", &date.day, &date.month, &date.year);
    return date;
}


int main() {
    Date a = {.day = 1, .month = 10, .year = 2022};
    print(a);
    a = input();
    print(a);

    return 0;
}
