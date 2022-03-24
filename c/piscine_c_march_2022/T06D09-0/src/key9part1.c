/*------------------------------------
	Здравствуй, человек!
	Чтобы получить ключ 
	поработай с комментариями.
-------------------------------------*/
// Copyright [2022] <griselle>

#include <stdio.h>

#define NMAX 10

int input(int *buffer, int *length);
void output(int *buffer, int length);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
	Функция получает массив данных 
	через stdin.
	Выдает в stdout особую сумму
	и сформированный массив 
	специальных элементов
	(выбранных с помощью найденной суммы):
	это и будет частью ключа
-------------------------------------*/
int main(void) {
    int in_arr[NMAX];
    int in_arr_length;
    int out_arr[NMAX];
    int out_arr_length;
    int sum;

    if (!input(in_arr, &in_arr_length)) {
        printf("n/a");
        return (1);
    }
    sum = sum_numbers(in_arr, in_arr_length);
    printf("%d\n", sum);
    out_arr_length = find_numbers(in_arr, in_arr_length, sum, out_arr);
    output(out_arr, out_arr_length);
    return (0);
}

int input(int *buffer, int *length) {
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
    while (new_ptr - buffer < *length - 1) {
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

void output(int *a, int n) {
    int *new_ptr;

    new_ptr = a;
    while (new_ptr - a < n) {
        printf("%d", *new_ptr++);
        if (new_ptr - a < n)
            printf(" ");
    }
}

/*------------------------------------
	Функция должна находить
	сумму четных элементов 
	с 0-й позиции.
-------------------------------------*/

int sum_numbers(int *buffer, int length) {
    int sum;
    int *new_ptr;

    new_ptr = buffer;
    sum = 0;
    while (new_ptr - buffer < length) {
        if ((*new_ptr % 2) == 0)
            sum += *new_ptr;
        new_ptr++;
    }
    return (sum);
}

/*------------------------------------
	Функция должна находить
	все элементы, на которые нацело
	делится переданное число и
	записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    int *new_buf1_ptr;
    int *new_buf2_ptr;

    new_buf1_ptr = buffer;
    new_buf2_ptr = numbers;
    while (new_buf1_ptr - buffer < length) {
        if (*new_buf1_ptr != 0) {
            if ((number % *new_buf1_ptr) == 0) {
                *new_buf2_ptr = *new_buf1_ptr;
                new_buf2_ptr++;
            }
        }
        new_buf1_ptr++;
    }
    return (new_buf2_ptr - numbers);
}
