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
    printf("---s21_strstr_test---\n");
    printf("Normal:\n\tSTR: 'TEST'\n\tSub: 'ST'\n\tRES:");
    s21_strstr_test(str, "ST", (str + 2));
    printf("\nAbnormal:\n\tSTR: 'TEST'\n\tSub: 'TG'\n\tRES:");
    s21_strstr_test(str, "TG", NULL);
    printf("\nBoundary:\n\tSTR: 'TEST'\n\tSub: ''\n\tRES:");
    s21_strstr_test(str, "", str);
    printf("\n");
    printf("END---s21_strstr_test---END\n");
    free(str);
    return (0);
}
