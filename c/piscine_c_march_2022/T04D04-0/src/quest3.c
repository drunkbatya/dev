// Copyright [2022] <griselle>
#include <stdio.h>

unsigned long long int fibbonacci(int index) {
    if (index < 0)
        return (-1);
    if (index == 0)
        return (0);
    if (index == 1)
        return (1);
    return (fibbonacci(index - 1) + fibbonacci(index - 2));
}

int get_only_uint(void) {
    char c;
    int out;
    int first_match_flag;

    first_match_flag = 1;
    out = 0;
    while ((c = getchar()) != '\n') {
        if (c < '0' || c > '9')
            return (-1);
        first_match_flag = 0;
        out = (out * 10) + (c - '0');
    }
    if (first_match_flag && out == 0)
        return (-1);
    return (out);
}

int main(void) {
    int num;
    unsigned long long int fib;

    num = get_only_uint();
    if (num < 0) {
        printf("n/a");
        return (1);
    }
    fib = fibbonacci(num);
    if (fib < 0) {
        printf("n/a");
        return (1);
    }
    printf("%llu", fib);
}
