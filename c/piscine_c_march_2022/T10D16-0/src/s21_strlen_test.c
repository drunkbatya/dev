// Copyright [2022] <griselle>

#include "s21_string_test.h"
#include "s21_string.h"
#include <stdio.h>

int main(void) {
    printf("---s21_strlen_test---\n");
    printf("Normal:\n\tSTR: 'QWER'\n\tExpected value: 4\n\tValue: %lu\n\tRES:", s21_strlen("QWER"));
    s21_strlen_test("QWER", 4);
    printf("\nAbnormal:\n\tSTR: '§'\n\tExpected value: 2\n\tValue: %lu\n\tRES:", s21_strlen("§"));
    s21_strlen_test("§", 2);
    printf("\nBoundary:\n\tSTR: ''\n\tExpected value: 0\n\tValue: %lu\n\tRES:", s21_strlen(""));
    s21_strlen_test("", 0);
    printf("\n");
    printf("END---s21_strlen_test---END\n");
    return (0);
}
