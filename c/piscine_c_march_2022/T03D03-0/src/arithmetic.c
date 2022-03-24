// Copyright [2022] <griselle>
#include <stdio.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);

int main() {
    int a;
    int b;

    if (scanf("%d %d", &a, &b) != 2) {
        printf("n/a");
        return (1);
    }
    printf("%d ", add(a, b));
    printf("%d ", sub(a, b));
    printf("%d ", mul(a, b));
    if (b == 0)
        printf("n/a");
    else
        printf("%d", div(a, b));
    return 0;
}

int add(int a, int b) {
    return (a + b);
}

int sub(int a, int b) {
    return (a - b);
}

int mul(int a, int b) {
    return (a * b);
}

int div(int a, int b) {
    return (a / b);
}
