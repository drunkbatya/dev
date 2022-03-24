// Copyright [2022] <griselle>

#include "s21_string_test.h"
#include "s21_string.h"
#include <stdio.h>

int main(void) {
    printf("---s21_strcpy_test---\n");
    printf("Normal:\n\tSTR: 'QW' and 'QW'\n\tExpected value: 0\n\tValue: %d\n\tRES:", s21_strcmp("QW", "QW"));
    s21_strcmp_test("QW", "QW", 0);
    printf("\nAbnormal:\n\tSTR: '§' and ''\n\tExpected value: -1\n\tValue: %d\n\tRES:", s21_strcmp("§", ""));
    s21_strcmp_test("§", "", -1);
    printf("\nBoundary:\n\tSTR: '' and ''\n\tExpected value: 0\n\tValue: %d\n\tRES:", s21_strcmp("", ""));
    s21_strcmp_test("", "", 0);
    printf("\n");
    printf("END---s21_strcpy_test---END\n");
    return (0);
}
