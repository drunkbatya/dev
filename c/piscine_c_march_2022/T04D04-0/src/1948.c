// Copyright [2022] <griselle>
#include <stdio.h>

double get_only_int(void) {
    // i use casting types to return signed numbers and service code.
    // if function returns "-0.26" - it means error.
    // Function returns int in any other casees.
    char c;
    double out;
    int first_match_flag;

    first_match_flag = 1;
    out = 0;
    while ((c = getchar()) != '\n') {
        if (c < '0' || c > '9')
            return (-0.26);
        first_match_flag = 0;
        out = (out * 10) + (c - '0');
    }
    if (first_match_flag && out == 0)
        return (-0.26);
    return (out);
}

int get_remainder(int num1, int num2) {
    while (num1 >= num2)
        num1 = num1 - num2;
    return (num1);
}

int is_prime(int num) {
    int count;

    count = 1;
    if (num < 2)
        return (0);
    if (num == 2)
        return (1);
    while (++count < num)
        if (get_remainder(num, count) == 0)
                return (0);
    return (1);
}

int get_highest_prime(int num) {
    int count;
    int out;

    count = 0;
    while (count <= num) {
        if (!is_prime(count)) {
            count++;
            continue;
        }
        if (get_remainder(num, count) != 0) {
            count++;
            continue;
        }
        out = count;
        count++;
    }
    return (out);
}

int main(void) {
    double num;
    int out;

    num = get_only_int();
    if (num == -0.26) {
        printf("n/a");
        return (1);
    }
    if (num < 0)
        num = -num;
    out = get_highest_prime(num);
    if (out)
        printf("%d", out);
    else
        printf("n/a");
    return (0);
}
