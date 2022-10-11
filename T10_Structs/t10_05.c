#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 81


typedef struct {
    char title[N];
    int height;
} Peak;


void print_peaks(Peak* peaks, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s %ld\n", peaks[i].title, peaks[i].height);
    }
}


Peak input() {
    Peak peak;
    scanf("%80s %ld", peak.title, &peak.height);
    return peak;
}


Peak heighest_peak(Peak* peaks, int n) {
    Peak max_peak = {.height = 0};
    for (int i = 0; i < n; i++) {
        if (peaks[i].height > max_peak.height) {
            max_peak = peaks[i];
        }
    }
    return max_peak;
}


int peak_height(Peak* peaks, int n, char* title) {
    for (int i = 0; i < n; i++) {
        if (strcmp(peaks[i].title, title) == 0) {
            return peaks[i].height;
        }
    }
    return -1;
}


int main() {
    int n = 3;
    Peak peaks[N] = {
        {"Hoverla", 2600},
        {"Everest", 8000},
        {"Elbrus", 5000}
    };
    peaks[n++] = input();
    print_peaks(peaks, n);

    Peak p = heighest_peak(peaks, n);
    printf("\nHeighest peak: ");
    print_peaks(&p, 1);

    char title[N];
    scanf("%80s", title);
    int height = peak_height(peaks, n, title);
    if (height != -1) {
        printf("Height: %ld", height);
    }

    return 0;
}
