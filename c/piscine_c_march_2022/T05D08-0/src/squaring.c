// Copyright [2022] <griselle>

#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
    int n, data[NMAX];
    if (!input(data, &n)) {
        printf("n/a");
        return (1);
    }
    squaring(data, n);
    output(data, n);

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

void squaring(int *a, int n) {
    int *new_ptr;

    new_ptr = a;
    while (new_ptr - a < n) {
        *new_ptr = *new_ptr * *new_ptr;
        new_ptr++;
    }
}
