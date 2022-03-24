// Copyright [2022] <griselle>
#include <stdio.h>
#include <math.h>

double agne(double num) {
    return (pow(1, 3) / (1 + pow(num, 2)));
}

double burnout(double num) {
    return (sqrt(sqrt(1 + 4 * pow(num , 2) * 1) - pow(num, 2) - 1));
}

double hype(double num) {
    return (1 / pow(num, 2));
}

void print_func_out(double out) {
    if (out != out)
        printf("-");
    else
        printf("%.7f", out);
}

int main(void) {
    double offset;
    double num;
    int count;

    count = 0;
    num = -M_PI;
    offset = 2 * M_PI / 41;
    while (count < 42) {
        printf("%.7f", num);
        printf(" | ");
        print_func_out(agne(num));
        printf(" | ");
        print_func_out(burnout(num));
        printf(" | ");
        print_func_out(hype(num));
        printf("\n");
        num = num + offset;
        count++;
    }
    return (0);
}

