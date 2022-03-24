// Copyright [2022] <griselle>

#include "documentation_module.h"
#include <stdarg.h>

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

int validate(char *data) {
    return (!s21_strcmp(data, Available_document));
}

int check_available_documentation_module(int (*validate)(char *), int document_count, ...) {
    int out;
    int count;
    va_list args;

    out = 0;
    count = 0;
    va_start(args, document_count);
    while (count < document_count) {
        out = (out << 1) + validate(va_arg(args, char *));
        count++;
    }
    va_end(args);
    return (out);
}
