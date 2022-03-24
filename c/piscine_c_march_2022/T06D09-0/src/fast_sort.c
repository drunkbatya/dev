// Copyright [2022] <griselle>

#include <stdio.h>

#define NMAX 10

int input(int *arr, int n);
void output(int *a, int n);
void arr_cpy(const int *arr1, int *arr2, int n);
void swap(int *num1, int *num2);
void fast_sort(int *arr, int first, int last);
void heap_sort(int *arr, int n);

int main(void) {
    int arr1[NMAX];
    int arr2[NMAX];

    if (!input(arr1, NMAX)) {
        printf("n/a");
        return (1);
    }
    arr_cpy(arr1, arr2, NMAX);
    fast_sort(arr1, 0, NMAX - 1);
    output(arr1, NMAX);
    printf("\n");
    heap_sort(arr2, NMAX);
    output(arr2, NMAX);
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

void arr_cpy(const int *arr1, int *arr2, int n) {
    int count;

    count = 0;
    while (count < n) {
        arr2[count] = arr1[count];
        count++;
    }
}

void swap(int *num1, int *num2) {
    int temp;

    temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}

void fast_sort(int *arr, int first, int last) {
    int left;
    int right;
    int middle;

    left = first;
    right = last;
    middle = arr[(left + right) / 2];
    if (last <= first)
        return;
    while (left <= right) {
        while (arr[left] < middle)
            left++;
        while (arr[right] > middle)
            right--;
        if (left > right)
            break;
        swap(arr + left, arr + right);
        right--;
        left++;
    }
    fast_sort(arr, first, right);
    fast_sort(arr, left, last);
}

void heap_sorter(int *arr, int n, int max) {
    int maxx;
    int left;
    int right;

    maxx = max;
    left = 2 * max + 1;
    right = 2 * max + 2;
    if (left < n && *(arr + left) > *(arr + maxx))
        maxx = left;
    if (right < n && *(arr + right) > *(arr + maxx))
        maxx = right;
    if (maxx == max)
        return;
    swap(arr + max, arr + maxx);
    heap_sorter(arr, n, maxx);
}

void heap_sort(int *arr, int n) {
    int count;

    count = n / 2 - 1;
    while (count >= 0) {
        heap_sorter(arr, n, count);
        count--;
    }
    count = n - 1;
    while (count >= 0) {
        swap(arr, arr + count);
        heap_sorter(arr, count, 0);
        count--;
    }
}
