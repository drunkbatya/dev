// Copyright [2022] <griselle>

#include <stdio.h>
#include <time.h>
#include "logger.h"

FILE *log_init(char *filename) {
    return (fopen(filename, "a"));
}

int log_close(FILE *log_file) {
    return (fclose(log_file));
}

char *get_log_prefix(log_level level) {
    if (level == info)
        return ("[INFO]");
    if (level == warning)
        return ("[WARNING]");
    if (level == error)
        return ("[ERROR]");
    if (level == debug)
        return ("[DEBUG]");
    return (NULL);
}

void get_current_date(char *tm_buf) {
    time_t timer;
    struct tm *tm_struct;

    timer = time(NULL);
    tm_struct = localtime(&timer);
    strftime(tm_buf, DATE_ARR_SIZE, " [%Y-%m-%d %X]: ", tm_struct);
}

int logcat(FILE *log_file, char *message, log_level level) {
    int tm_count;
    char *prefix;
    char tm_buf[DATE_ARR_SIZE];

    tm_count = 0;
    if (log_file == NULL)
        return (0);
    if (message == NULL)
        return (0);
    if (!(*message))
        return (0);
    prefix = get_log_prefix(level);
    if (prefix == NULL)
        return (0);
    while (*prefix)
        putc(*prefix++, log_file);
    get_current_date(tm_buf);
    while (tm_count < DATE_ARR_SIZE)
        putc(tm_buf[tm_count++], log_file);
    while (*message)
        putc(*message++, log_file);
    putc('\n', log_file);
    return (1);
}
