// Copyright [2022] <griselle>
#include <stdio.h>
#define RADIUS 5

void print_is_inside(float x, float y);

int main(void) {
    float x;
    float y;

    if (scanf("%f %f", &x, &y) != 2) {
        printf("n/a");
        return (1);
    }
    print_is_inside(x, y);
    return (0);
}

void print_is_inside(float x, float y) {
    if ((x * x) + (y * y) < (RADIUS * RADIUS))
        printf("GOTCHA");
    else
        printf("MISS");
}
