// Copyright [2022] <griselle>

#include "s21_string_test.h"
#include "s21_string.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char *str;

    str = malloc((s21_strlen("TEST ME I AM") * sizeof(char)) + 1);
    if (str == NULL) {
        printf("Memmory allocation error!");
        return (1);
    }
    s21_strcpy(str, "TEST ME I AM");
    s21_strtok(str, " ");
    printf("%s", str);
    printf("---s21_strtok_test---\n");
    printf("Normal:\n\tSTR: 'ME'\n\tRES:");
    s21_strtok_test(str, " ", "ME");
    printf("\nAbnormal:\n\tSTR: 'I'\n\tChar: 'W'\n\tRES:");
    s21_strtok_test(str, " ", "I");
    printf("\nBoundary:\n\tSTR: 'TEST'\n\tChar: '\\0'\n\tRES:");
    s21_strtok_test(str, " ", "AM");
    printf("\n");
    printf("END---s21_strtok_test---END\n");
    free(str);
    return (0);
}
