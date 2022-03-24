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
    s21_strcpy(str, "TEST");
    printf("---s21_strchr_test---\n");
    printf("Normal:\n\tSTR: 'TEST'\n\tChar: 'S'\n\tRES:");
    s21_strchr_test(str, 'S', (str + 2));
    printf("\nAbnormal:\n\tSTR: 'TEST'\n\tChar: 'W'\n\tRES:");
    s21_strchr_test(str, 'W', NULL);
    printf("\nBoundary:\n\tSTR: 'TEST'\n\tChar: '\\0'\n\tRES:");
    s21_strchr_test(str, '\0', (str + 4));
    printf("\n");
    printf("END---s21_strchr_test---END\n");
    free(str);
    return (0);
}
