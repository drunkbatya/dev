// Copyright [2022] <griselle>

#include <stdio.h>

#define NMAX 10

int input(int *arr, int n);
void output(int *arr, int n);
void sort(int *arr, int num);

int main(void) {
    int arr[NMAX];

    if (!input(arr, NMAX)) {
        printf("n/a");
        return (1);
    }
    sort(arr, NMAX);
    output(arr, NMAX);
    return (0);
}

int input(int *arr, int n) {
    char c;
    int *new_ptr;

    c = 0;
    new_ptr = arr;
    while (new_ptr - arr < n - 1) {
        if (scanf("%d%c", new_ptr, &c) != 2)
            return (0);
        if (c != '\n' && c != ' ')
            return (0);
        new_ptr++;
    }
    if (scanf("%d", new_ptr) != 1)
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

void sort(int *arr, int num) {
    int temp;
    int count1;

    count1 = 0;
    while (count1 < num - 1) {
        int count2;

        count2 = 0;
        while (count2 < num - count1 - 1) {
            if (arr[count2] > arr[count2 + 1]) {
                temp = arr[count2 + 1];
                arr[count2 + 1] = arr[count2];
                arr[count2] = temp;
            }
            count2++;
        }
        count1++;
    }
}
