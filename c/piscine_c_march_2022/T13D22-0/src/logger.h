// Copyright [2022] <griselle>

#ifndef SRC_LOGGER_H_
#define SRC_LOGGER_H_

#define DATE_ARR_SIZE 25

typedef enum e_log_level {
    info,
    warning,
    error,
    debug
} log_level;

FILE *log_init(char *filename);
int logcat(FILE *log_file, char *message, log_level level);
int log_close(FILE *log_file);
#endif  // SRC_LOGGER_H_
