// Copyright [2022] <griselle>

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "print_module.h"

void print_char(char ch) {
    return (void)putchar(ch);
}

void print_log(void (*print)(char), char *message) {
    int tm_count;
    char *prefix;
    char tm_buf[10];
    time_t timer;
    struct tm *tm_struct;

    tm_count = 0;
    timer = time(NULL);
    tm_struct = localtime(&timer);
    strftime(tm_buf, 10, " %H:%M:%S ", tm_struct);
    prefix = Log_prefix;
    while (*prefix)
        print(*prefix++);
    while (tm_count < 10)
        print(tm_buf[tm_count++]);
    while (*message)
        print(*message++);
}
