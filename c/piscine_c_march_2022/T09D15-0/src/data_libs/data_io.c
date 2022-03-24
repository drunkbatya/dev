// Copyright [2022] <griselle>
#include "data_io.h"
#include <stdio.h>
#include <stdlib.h>

int input(double **data, int *n) {
    char c;
    double *new_ptr;

    c = 0;
    if (scanf("%d%c", n, &c) != 2)
        return (0);
    if (c != '\n' && c != ' ')
        return (0);
    if (*n < 1)
        return (0);
    *data = malloc(*n * sizeof(double));
    if (*data == NULL)
        return (0);
    new_ptr = *data;
    while (new_ptr - *data < *n - 1) {
        if (scanf("%lf%c", new_ptr, &c) != 2)
            return (0);
        if (c != '\n' && c != ' ')
            return (0);
        new_ptr++;
    }
    if (scanf("%lf", new_ptr) != 1)
        return (0);
    if (scanf("%c", &c) != EOF && c != '\n')
        return (0);
    return (1);
}

void output(double *data, int n) {
    double *new_ptr;

    new_ptr = data;
    while (new_ptr - data < n) {
        printf("%.2lf", *new_ptr);
        if (new_ptr - data < n - 1)
            printf(" ");
        new_ptr++;
    }
}
