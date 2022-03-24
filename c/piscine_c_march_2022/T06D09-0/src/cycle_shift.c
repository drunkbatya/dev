// Copyright [2022] <griselle>
#include <stdio.h>

#define NMAX 10

int input(int *buffer, int *length, int *shift);
void output(int *arr, int n);
void shift_it(int *arr, int n, int shift);

int main(void) {
    int arr[NMAX];
    int n;
    int shift;

    if (!input(arr, &n, &shift)) {
        printf("n/a");
        return (1);
    }
    shift_it(arr, n, shift);
    output(arr, n);
    return (0);
}

int input(int *buffer, int *length, int *shift) {
    char c;
    int *new_ptr;

    c = 0;
    new_ptr = buffer;
    if (scanf("%d%c", length, &c) != 2)
        return (0);
    if (c != '\n' && c != ' ')
        return (0);
    if (*length > NMAX)
        return (0);
    if (*length < 1)
        return (0);
    while (new_ptr - buffer < *length) {
        if (scanf("%d%c", new_ptr, &c) != 2)
            return (0);
        if (c != '\n' && c != ' ')
            return (0);
        new_ptr++;
    }
    if (scanf("%d", shift) != 1)
        return (0);
    if (scanf("%c", &c) != EOF && c != '\n')
        return (0);
    return (1);
}

void output(int *arr, int n) {
    int *new_ptr;

    new_ptr = arr;
    while (new_ptr - arr < n) {
        printf("%d", *new_ptr++);
        if (new_ptr - arr < n)
            printf(" ");
    }
}

void shift_right(int *arr, int n) {
    int last_element;
    int *new_ptr;

    new_ptr = arr + n - 1;
    last_element = *new_ptr;;
    while (new_ptr != arr) {
        *new_ptr = *(new_ptr - 1);
        new_ptr--;
    }
    *new_ptr = last_element;
}

void shift_left(int *arr, int n) {
    int first_element;
    int *new_ptr;

    new_ptr = arr;
    first_element = *new_ptr;
    while (new_ptr - arr < n - 1) {
        *new_ptr = *(new_ptr + 1);
        new_ptr++;
    }
    *new_ptr = first_element;
}

void shift_it(int *arr, int n, int shift) {
    while (shift != 0) {
        if (shift < 0) {
            shift_right(arr, n);
            shift++;
        }
        if (shift > 0) {
            shift_left(arr, n);
            shift--;
        }
    }
}
