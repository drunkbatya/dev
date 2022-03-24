// Copyright [2022] <griselle>

#include "s21_string_test.h"
#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *str;

    str = malloc((s21_strlen("TEST") * sizeof(char)) + 1);
    if (str == NULL) {
        printf("Memmory allocation error!");
        return (1);
    }
    printf("---s21_strcpy_test---\n");
    printf("Normal:\n\tSTR: 'TEST'\n\tNEW STR SIZE: 5\n\tRES:");
    s21_strcpy_test("TEST", str, 0);
    printf("\nAbnormal:\n\tSTR: 'TESTTT'\n\tNEW STR SIZE: 5\n\tRES:");
    s21_strcpy_test("TESTTT", str, 0);
    printf("\nBoundary:\n\tSTR: ''\n\tNEW STR SIZE: 5\n\tRES:");
    s21_strcpy_test("", str, -1);
    printf("\n");
    printf("END---s21_strcpy_test---END\n");
    free(str);
    return (0);
}
