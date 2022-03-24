// Copyright [2022] <griselle>

#include "s21_string.h"
#include <stdio.h>

unsigned long s21_strlen(const char *str) {
    const char *ptr;

    ptr = str;
    while (*ptr != '\0')
        ptr++;
    return (ptr - str);
}

int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 == *str2) {
        if (*str1 == '\0')
            return (0);
        str1++;
        str2++;
    }
    if (*str1 > *str2)
        return (1);
    return (-1);
}


char *s21_strcpy(char *dst, const char *src) {
    char *new_dst_ptr;

    new_dst_ptr = dst;
    while (*src != '\0') {
        *new_dst_ptr = *src;
        src++;
        new_dst_ptr++;
    }
    *new_dst_ptr = '\0';
    return (dst);
}

char *s21_strcat(char *str1, const char *str2) {
    char *new_str1_ptr;

    new_str1_ptr = str1;
    while (*new_str1_ptr != '\0')
        new_str1_ptr++;
    while (*str2 != '\0') {
        *new_str1_ptr = *str2;
        str2++;
        new_str1_ptr++;
    }
    *new_str1_ptr = '\0';
    return (str1);
}

char *s21_strchr(const char *str, int c) {
    while (*str != '\0') {
        if (*str == c)
            return ((char *)str);
        str++;
    }
    if (c == '\0')
        return ((char *)str);
    return (NULL);
}

char *s21_strstr(const char *str, const char *substr) {
    if (*substr == '\0')
        return ((char *)str);
    while (*str != '\0') {
        if (s21_strcmp(str, substr) == 0)
            return ((char *) str);
        str++;
    }
    return (NULL);
}

char *s21_strtok(char *str, const char *sep) {
    static char **str_last;

    if (str == NULL)
        str = *str_last;
    while (*str && s21_strchr(str, *sep))
        str++;
    if (!*str)
        return (NULL);
    *str_last = str + 1;
    while (**str_last && !s21_strchr(sep, **str_last))
        ++*str_last;
    if (**str_last) {
        **str_last = '\0';
        ++*str_last;
    }
    return (str);
}
