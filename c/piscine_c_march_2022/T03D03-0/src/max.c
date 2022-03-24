// Copyright [2022] <griselle>
#include <stdio.h>

int max(int a, int b);

int main(void) {
    int a;
    int b;

    if (scanf("%d %d", &a, &b) != 2) {
        printf("n/a");
        return (1);
    }
    printf("%d", max(a, b));
    return (0);
}

int max(int a, int b) {
    if (a > b)
        return (a);
    else
        return (b);
}
