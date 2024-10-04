#include <stdio.h>


typedef struct Date {
    int day, month, year;
} Date;

Date input() {
    Date date;
    scanf("%li.%li.%li", &date.day, &date.month, &date.year);
    return date;
}
void print(Date date) {
    printf("%02li.%02li.%li\n", date.day, date.month, date.year);
}


int main() {
    Date date = input();
    print(date);

    return 0;
}
