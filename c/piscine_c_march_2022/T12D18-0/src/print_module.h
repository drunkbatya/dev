// Copyright [2022] <griselle>

#ifndef SRC_PRINT_MODULE_H_

#define SRC_PRINT_MODULE_H_
#define Module_load_success_message "Output stream module load: success\n"
#define Log_prefix "[LOG]"

void print_log(void (*print)(char), char *message);
void print_char(char ch);
#endif  // SRC_PRINT_MODULE_H_
