// Copyright [2022] <griselle>

#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v);

int main(void) {
    int n, data[NMAX];
    if (!input(data, &n)) {
        printf("n/a");
        return (1);
    }
    output(data, n);
    output_result(max(data, n),
                  min(data, n),
                  mean(data, n),
                  variance(data, n));
    return 0;
}

int input(int *a, int *n) {
    char c;

    c = 0;
    if (scanf("%d%c", n, &c) != 2)
        return (0);
    if (c != '\n')
        return (0);
    if (*n > NMAX)
        return (0);
    if (*n < 1)
        return (0);
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d%c", p, &c) != 2)
            return (0);
        if (c != '\n' && c != ' ')
            return (0);
    }
    return (1);
}

void output(int *a, int n) {
    int *new_ptr;

    new_ptr = a;
    while (new_ptr - a < n) {
        printf("%d", *new_ptr++);
        if (new_ptr - a < n)
            printf(" ");
    }
}

int max(int *a, int n) {
    int *new_ptr;
    int out_number;

    new_ptr = a;
    out_number = 0;
    while (new_ptr - a < n) {
        if (*new_ptr > out_number)
            out_number = *new_ptr;
        new_ptr++;
    }
    return (out_number);
}

int min(int *a, int n) {
    int *new_ptr;
    int out_number;

    new_ptr = a;
    out_number = max(a, n);
    while (new_ptr - a < n) {
        if (*new_ptr < out_number)
            out_number = *new_ptr;
        new_ptr++;
    }
    return (out_number);
}

double mean(int *a, int n) {
    int *new_ptr;
    double out_number;

    new_ptr = a;
    out_number = 0.0;
    while (new_ptr - a < n)
        out_number += *new_ptr++;
    return (out_number / n);
}

double variance(int *a, int n) {
    int *new_ptr;
    double out_number;
    double mean_value;

    new_ptr = a;
    out_number = 0.0;
    mean_value = mean(a, n);
    while (new_ptr - a < n) {
        out_number += (*new_ptr - mean_value) * (*new_ptr - mean_value);
        new_ptr++;
    }
    return (out_number / n);
}

void output_result(int max_v,
                   int min_v,
                   double mean_v,
                   double variance_v) {
    printf("\n");
    printf("%d ", max_v);
    printf("%d ", min_v);
    if (mean_v != mean_v)
        printf("n/a ");
    else
        printf("%.6lf ", mean_v);
    if (variance_v != variance_v)
        printf("n/a");
    else
        printf("%.6lf", variance_v);
}
