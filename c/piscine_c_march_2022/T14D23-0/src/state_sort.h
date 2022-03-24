// Copyright [2022] <griselle>

#ifndef SRC_STATE_SORT_H_
#define SRC_STATE_SORT_H_

typedef struct s_date {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int status;
    int code;
} date;

int add_to_file(FILE *file_ptr, char *text);
int make_me_free(char *file_path, FILE *file_ptr, char *text, int exit_code);
int menu(char **file_path, FILE **file_ptr, char **text);
void print_file(FILE *file_ptr);
int read_string(char **str);
int read_cmd(void);
int open_file(char *filename, FILE **file_ptr, char *mode);
date *read_record_from_file(FILE *pfile, int index);
void write_record_in_file(FILE *pfile, const date *record_to_write, int index);
void swap_records_in_file(FILE *pfile, int record_index1, int record_index2);
int get_file_size_in_bytes(FILE *pfile);
int get_records_count_in_file(FILE *pfile);
void print_struct(date *record);
int compare_records(FILE *pfile, int record_index1, int record_index2);
void sort(FILE *file_ptr);
void sort_file(FILE *file_ptr);
int count_sym(char *str, char sym);
#endif  // SRC_STATE_SORT_H_
