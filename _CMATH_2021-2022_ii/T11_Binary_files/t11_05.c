#include <stdio.h>
#include <stdlib.h>
#define F "F.poly"
#define N 100


typedef struct {
    double coef;
    int deg;
} Monom;


typedef struct {
    int m;
    Monom monoms[N];
} Poly;


Poly create_poly(double* row, int m) {
    Poly p;
    p.m = 0;
    for (int i = 0; i < m; i++) {
        if (row[i] != 0) {
            Monom monom = {row[i], i};
            p.monoms[p.m] = monom;
            p.m++;
        }
    }
    return p;
}


void print_poly(Poly p) {
    int i;
    for (i = 0; i < p.m - 1; i++) {
        printf("%.2lfx^%ld + ", p.monoms[i].coef, p.monoms[i].deg);
    }
    printf("%.2lfx^%ld\n", p.monoms[i].coef, p.monoms[i].deg);
}


void print_polynoms(Poly* ps, int n) {
    for (int i = 0; i < n; i++)
        print_poly(ps[i]);
}


void write_polynoms_to_file(Poly* ps, int n, char* filename) {
    FILE* f = fopen(filename, "wb");
    if (!f) exit(1);

    fwrite(&n, sizeof (int), 1, f);
    for (int i = 0; i < n; i++) {
        fwrite(&ps[i].m, sizeof (int), 1, f);
        fwrite(ps[i].monoms, sizeof (Monom), ps[i].m, f);
    }

    fclose(f);
}


int read_polynoms_from_file(Poly* ps, char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) exit(1);

    int n;
    fread(&n, sizeof (int), 1, f);
    for (int i = 0; i < n; i++) {
        fread(&ps[i].m, sizeof (int), 1, f);
        fread(ps[i].monoms, sizeof (Monom), ps[i].m, f);
    }

    fclose(f);
    return n;
}


Poly read_k_poly_from_file(int k, char* filename) {
    FILE* f = fopen(filename, "rb");
    if (!f) exit(1);

    int n;
    fread(&n, sizeof (int), 1, f);
    if (k > n)
        exit(1);

    k--;
    int m;
    for (int i = 0; i < k; i++) {
        fread(&m, sizeof (int), 1, f);
        fseek(f, m * sizeof (Monom), SEEK_CUR);
    }
    Poly p;
    fread(&p.m, sizeof (int), 1, f);
    fread(p.monoms, sizeof (Monom), p.m, f);

    fclose(f);
    return p;
}


void append_poly_to_file(Poly p, char* filename) {
    FILE* f = fopen(filename, "rb+");
    if (!f) exit(1);

    int n;
    fread(&n, sizeof (int), 1, f);
    n++;
    rewind(f);
    fwrite(&n, sizeof (int), 1, f);

    fseek(f, 0, SEEK_END);
    fwrite(&p.m, sizeof (int), 1, f);
    fwrite(p.monoms, sizeof (Monom), p.m, f);

    fclose(f);
}


int main() {
    int n = 4;
    int m = 7;
    double arr[N][N] = {
        {1.0, 0.23, 0.0, -4.0, 6.4, 0.0, 7.2},
        {0.0, 0.2, -1.0, 0.0, 1.4, 1.0, 1.2},
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 4.7},
        {0.2, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0},
    };
    Poly polynoms[N];
    for (int i = 0; i < n; i++)
        polynoms[i] = create_poly(arr[i], m);

    write_polynoms_to_file(polynoms, n - 1, F);
    append_poly_to_file(polynoms[n - 1], F);

    Poly polynoms_from_file[N];
    int n_ = read_polynoms_from_file(polynoms_from_file, F);
    print_polynoms(polynoms_from_file, n_);

    int k = 4;
    Poly p = read_k_poly_from_file(k, F);
    print_poly(p);

    return 0;
}
