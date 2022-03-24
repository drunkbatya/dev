// Copyright [2022] <griselle>

#include "s21_string_test.h"
#include "s21_string.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    char *str;

    str = malloc(((s21_strlen("TEST") + s21_strlen("ME")) * sizeof(char)) + 1);
    if (str == NULL) {
        printf("Memmory allocation error!");
        return (1);
    }
    printf("---s21_strcat_test---\n");
    printf("Normal:\n\tADD STR: 'ME'\n\tNEW STR SIZE: 2\n\tRES:");
    s21_strcat_test(s21_strcpy(str, "TEST"), "ME", 2);
    printf("\nAbnormal:\n\tADD STR: ''\n\tNEW STR SIZE: 0\n\tRES:");
    s21_strcat_test(s21_strcpy(str, "TEST"), "", 2);
    printf("\nBoundary:\n\tADD STR: 'MEE'\n\tNEW STR SIZE: 3\n\tRES:");
    s21_strcat_test(s21_strcpy(str, "TEST"), "MEE", 5);
    printf("\n");
    printf("END---s21_strcat_test---END\n");
    free(str);
    return (0);
}
