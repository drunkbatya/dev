// Copyright [2022] <griselle>
#include <stdio.h>
#include <math.h>

float calc(float num);

int main(void) {
    float number;

    if (scanf("%f", &number) != 1) {
        printf("n/a");
        return (1);
    }
    if (number == 0) {
        printf("n/a");
        return (1);
    }
    printf("%.1f", calc(number));
}

float calc(float num) {
    float out;

    out = 7e-3 * pow(num, 4) + ((22.8 * pow(num, (1/3)) - 1e3) * num + 3);
    out = out / (num * num / 2) - num * pow((10 + num), (2 / num)) - 1.01;
    return (out);
}
