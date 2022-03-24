// Copyright [2022] <griselle>
#include <stdio.h>

#define LEN 100

void sum(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void sub(int *buff1, int len1, int *buff2, int len2, int *result, int *result_length);
void zero_arr(int *arr, int n);
int input(int *arr1, int *arr2, int *arr1_len, int *arr2_len);
void output(int *arr, int n);
void sum_two_arr(int *arr1, int *arr2, int *out_arr, int arr1_len, int arr2_len, int *out_arr_len);

/*
    Беззнаковая целочисленная длинная арифметика
    с использованием массивов.
    Ввод: 
     * 2 длинных числа в виде массивов до 100 элементов
     * В один элемент массива нельзя вводить число > 9
    Вывод: 
     * Результат сложения и разности чисел-массивов
    Пример:
     * 1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 6 1
       2 9

       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 9 0
       1 9 4 4 6 7 4 4 0 7 3 7 0 9 5 5 1 3 2
*/
int main(void) {
    int arr1[LEN];
    int arr2[LEN];
    int arr_sum[LEN + 1];
    int arr1_len;
    int arr2_len;
    int arr_sum_len;

    if (!input(arr1, arr2, &arr1_len, &arr2_len)) {
        printf("n/a");
        return (1);
    }
    zero_arr(arr_sum, LEN + 1);
    sum_two_arr(arr1, arr2, arr_sum, arr1_len, arr2_len, &arr_sum_len);
    output(arr_sum, arr_sum_len);
    return (0);
}

int input_char_to_arr(int *arr, int *n) {
    char ctl;
    char c;
    int *new_ptr;

    ctl = 0;
    c = 0;
    new_ptr = arr;
    while (ctl != '\n') {
        if (new_ptr - arr > LEN - 1)
            return (0);
        if (scanf("%c", &c) != 1)
            return (0);
        if (c < '0' || c > '9')
            return (0);
        if (scanf("%c", &ctl) != 1)
            return (0);
        if (ctl != ' ' && ctl != '\n')
            return (0);
        *new_ptr = c - '0';
        if (ctl != '\n')
            new_ptr++;
    }
    *n = new_ptr - arr + 1;
    return (1);
}

int input(int *arr1, int *arr2, int *arr1_len, int *arr2_len) {
    if (!input_char_to_arr(arr1, arr1_len))
        return (0);
    if (!input_char_to_arr(arr2, arr2_len))
        return (0);
    return (1);
}

void zero_arr(int *arr, int n) {
    int *new_ptr;

    new_ptr = arr;
    while (new_ptr - arr < n) {
        *new_ptr = 0;
        new_ptr++;
    }
}

void sum_two_arr(int *arr1, int *arr2, int *out_arr, int arr1_len, int arr2_len, int *out_arr_len) {
    int max_len;
    int count;

    count = 0;
    arr1_len -= 1;
    arr2_len -= 1;
    max_len = arr1_len;
    if (arr2_len > arr1_len)
        max_len = arr2_len;
    while (count < max_len + 1) {
        int temp;

        temp = 0;
        if (arr1_len >= count)
            temp += *(arr1 + arr1_len - count);
        if (arr2_len >= count)
            temp += *(arr2 + arr2_len - count);
        *(out_arr + max_len - count + 1) = *(out_arr + max_len - count + 1) + temp;
        if (*(out_arr + max_len - count + 1) > 9) {
            *(out_arr + max_len - count) = *(out_arr + max_len - count + 1) / 10;
            *(out_arr + max_len - count + 1) = *(out_arr + max_len - count + 1) % 10;
        }
        count++;
    }
    *out_arr_len = count + 1;
}

void output(int *arr, int n) {
    int *new_ptr;
    int left_zero_flag;

    new_ptr = arr;
    left_zero_flag = 1;
    while (new_ptr - arr < n) {
        if (*new_ptr != 0)
            left_zero_flag = 0;
        if (left_zero_flag) {
            new_ptr++;
            continue;
        }
        printf("%d", *new_ptr++);
        if (new_ptr - arr < n)
            printf(" ");
    }
}
