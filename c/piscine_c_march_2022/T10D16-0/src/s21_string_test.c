// Copyright [2022] <griselle>

#include "s21_string.h"
#include <stdlib.h>
#include <stdio.h>

void s21_strlen_test(const char *str, unsigned long true_size) {
    if (s21_strlen(str) == true_size)
        return ((void) printf("SUCCESS"));
    printf("FAIL");
}

void s21_strcmp_test(const char *str1, const char *str2, int expect_value) {
    if (s21_strcmp(str1, str2) == expect_value)
        return ((void) printf("SUCCESS"));
    printf("FAIL");
}

void s21_strcpy_test(const char *str1, char *str2, int expect_cmp_result) {
    if (s21_strcmp(str1, s21_strcpy(str2, str1)) == expect_cmp_result)
        return ((void) printf("SUCCESS"));
    printf("FAIL");
}

void s21_strcat_test(char *str1, const char *str2, unsigned long expect_len_result) {
    if (s21_strlen(s21_strcat(str1, str2)) == expect_len_result)
        return ((void) printf("SUCCESS"));
    printf("FAIL");
}

void s21_strchr_test(char *str, const int c, const char *expected_ptr) {
    if ((s21_strchr(str, c)) == expected_ptr)
        return ((void) printf("SUCCESS"));
    printf("FAIL");
}

void s21_strstr_test(const char *str, const char *substr, const char *expected_ptr) {
    if ((s21_strstr(str, substr)) == expected_ptr)
        return ((void) printf("SUCCESS"));
    printf("FAIL");
}

void s21_strtok_test(char *str, const char *sep, const char *expected_str) {
    str = s21_strtok(NULL, sep);
    if (s21_strcmp(str, expected_str) == 0)
        return ((void) printf("SUCCESS"));
    printf("FAIL");
}
