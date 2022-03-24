// Copyright [2022] <griselle>

#include <stdio.h>
#include <math.h>
#define NMAX 30

int input(int *a, int *n);
double mean(int *a, int n);
double variance(int *a, int n);
int check_number(int *a, int size, int pos);
int find(int *a, int n);

int main(void) {
    int n;
    int data[NMAX];

    if (!input(data, &n)) {
        printf("n/a");
        return (1);
    }
    printf("%d", find(data, n));
    return (0);
}

int input(int *a, int *n) {
    char c;
    int *new_ptr;

    c = 0;
    new_ptr = a;
    if (scanf("%d%c", n, &c) != 2)
        return (0);
    if (c != '\n')
        return (0);
    if (*n > NMAX)
        return (0);
    if (*n < 1)
        return (0);
    while (new_ptr - a < *n) {
        if (scanf("%d%c", new_ptr, &c) != 2)
            return (0);
        if (c != '\n' && c != ' ')
            return (0);
        new_ptr++;
    }
    return (1);
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

int check_number(int *a, int size, int pos) {
    if ((*(a + pos) % 2) != 0)
        return (0);
    if (*(a + pos) < mean(a, size))
        return (0);
    if (*(a + pos) > (mean(a, size) + 3 * sqrt(variance(a, size))))
        return (0);
    if (*(a + pos) == 0)
        return (0);
    return (1);
}

int find(int *a, int n) {
    int *new_ptr;

    new_ptr = a;
    while (new_ptr - a < n) {
        if (check_number(a, n, (new_ptr - a)))
            return (*new_ptr);
        new_ptr++;
    }
    return (0);
}
