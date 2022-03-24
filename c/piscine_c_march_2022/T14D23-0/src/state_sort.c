// Copyright [2022] <griselle>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "state_sort.h"

int main(void) {
    char *file_path;
    FILE *file_ptr;
    char *text;

    file_path = NULL;
    file_ptr = NULL;
    text = NULL;
    if (!menu(&file_path, &file_ptr, &text)) {
        printf("n/a");
        return (make_me_free(file_path, file_ptr, text, 1));
    }
    return (make_me_free(file_path, file_ptr, text, 0));
}

// i'm realy sorry for this functon
int compare_records(FILE *pfile, int record_index1, int record_index2) {
    date *record1;
    date *record2;

    record1 = read_record_from_file(pfile, record_index1);
    if (record1 == NULL)
        return (-1);
    record2 = read_record_from_file(pfile, record_index2);
    if (record2 == NULL) {
        free(record1);
        return (-1);
    }
    if (record2->year > record1->year) {
        free(record1);
        free(record2);
        return (1);
    }
    if (record2->year != record1->year) {
        free(record1);
        free(record2);
        return (0);
    }
    if (record2->month > record1->month) {
        free(record1);
        free(record2);
        return (1);
    }
    if (record2->month != record1->month) {
        free(record1);
        free(record2);
        return (0);
    }
    if (record2->day > record1->day) {
        free(record1);
        free(record2);
        return (1);
    }
    if (record2->day != record1->day) {
        free(record1);
        free(record2);
        return (0);
    }
    if (record2->hour > record1->hour) {
        free(record1);
        free(record2);
        return (1);
    }
    if (record2->hour != record1->hour) {
        free(record1);
        free(record2);
        return (0);
    }
    if (record2->minute > record1->minute) {
        free(record1);
        free(record2);
        return (1);
    }
    if (record2->minute != record1->minute) {
        free(record1);
        free(record2);
        return (0);
    }
    if (record2->second > record1->second) {
        free(record1);
        free(record2);
        return (1);
    }
    if (record2->second != record1->second) {
        free(record1);
        free(record2);
        return (0);
    }
    if (record2->status > record1->status) {
        free(record1);
        free(record2);
        return (1);
    }
    if (record2->status != record1->status) {
        free(record1);
        free(record2);
        return (0);
    }
    if (record2->code > record1->code) {
        free(record1);
        free(record2);
        return (1);
    }
    if (record2->code != record1->code) {
        free(record1);
        free(record2);
        return (0);
    }
    return (0);
}

void sort(FILE *file_ptr) {
    int file_len;
    int count1;

    file_len = get_records_count_in_file(file_ptr);
    count1 = 0;
    while (count1 < file_len - 1) {
        int count2;

        count2 = 0;
        while (count2 < file_len - count1 - 1) {
            if (compare_records(file_ptr, count2 + 1, count2))
                swap_records_in_file(file_ptr, count2 + 1, count2);
            count2++;
        }
        count1++;
    }
}

int make_me_free(char *file_path, FILE *file_ptr, char *text, int exit_code) {
    if (file_path)
        free(file_path);
    if (file_ptr)
        fclose(file_ptr);
    if (text)
        free(text);
    return (exit_code);
}

int count_sym(char *str, char sym) {
    int count;

    count = 0;
    while (*str != '\0') {
        if (*str == sym)
            count++;
        str++;
    }
    return (count);
}

int menu(char **file_path, FILE **file_ptr, char **text) {
    int cmd;

    if (!read_string(file_path))
        return (0);
    if (!open_file(*file_path, file_ptr, "r+b"))
        return (0);
    cmd = read_cmd();
    if (cmd == 0) {
        printf("cmd 0\n");
        print_file(*file_ptr);
        return (1);
    }
    if (cmd == 1) {
        sort(*file_ptr);
        print_file(*file_ptr);
        return (1);
    }
    if (cmd == 2) {
        if (!read_string(text))
            return (0);
        if (!add_to_file(*file_ptr, *text))
            return (0);
        sort(*file_ptr);
        print_file(*file_ptr);
        return (1);
    }
    return (0);
}

int add_to_file(FILE *file_ptr, char *text) {
    int index;
    date *ptr;

    if (count_sym(text, ' ') != 7)
        return (0);
    ptr = malloc(sizeof(date));
    if (ptr == NULL)
        return (0);
    index = get_records_count_in_file(file_ptr);
    // TODO(griselle): check NULLLLLLS
    ptr->year = atoi(strtok(text, " "));
    ptr->month = atoi(strtok(NULL, " "));
    ptr->day = atoi(strtok(NULL, " "));
    ptr->hour = atoi(strtok(NULL, " "));
    ptr->minute = atoi(strtok(NULL, " "));
    ptr->second = atoi(strtok(NULL, " "));
    ptr->status = atoi(strtok(NULL, " "));
    ptr->code = atoi(strtok(NULL, " "));
    write_record_in_file(file_ptr, ptr, index);
    free(ptr);
    return (1);
}

void print_file(FILE *file_ptr) {
    date *temp;
    int count;
    int records_count;

    temp = NULL;
    count = 0;
    records_count = get_records_count_in_file(file_ptr);
    if (!records_count)
        return;
    while (count < records_count) {
        if (temp != NULL) {
            free(temp);
            temp = NULL;
        }
        temp = read_record_from_file(file_ptr, count);
        if (temp == NULL)
            return;
        print_struct(temp);
        count++;
    }
    if (temp != NULL)
        free(temp);
}

int read_string(char **str) {
    int c;

    *str = calloc(2, sizeof(char));
    if (*str == NULL)
        return (0);
    c = getchar();
    while (c != EOF && c != '\n') {
        if (c != EOF && c <= 0)
            continue;
        *str = realloc(*str, (strlen(*str) + 2));
        if (*str == NULL)
            return (0);
        *(*str + strlen(*str)) = c;
        c = getchar();
    }
    if (!strlen(*str))
        return (0);
    return (1);
}

int read_cmd(void) {
    int c;
    int cmd;

    c = getchar();
    if (c < '0' || c > '9')
        return (-1);
    cmd = c - '0';
    c = getchar();
    if (c == '\n' || c == ' ')
        return (cmd);
    return (-1);
}

int open_file(char *filename, FILE **file_ptr, char *mode) {
    if (*file_ptr != NULL)
        fclose(*file_ptr);
    *file_ptr = fopen(filename, mode);
    if (*file_ptr == NULL)
        return (0);
    return (1);
}

date *read_record_from_file(FILE *pfile, int index) {
    int offset;
    date *record;

    record = malloc(sizeof(date));
    if (record == NULL)
        return (record);
    offset = index * sizeof(date);
    fseek(pfile, offset, SEEK_SET);
    fread(record, sizeof(date), 1, pfile);
    rewind(pfile);
    return (record);
}
void write_record_in_file(FILE *pfile, const date *record_to_write, int index) {
    int offset;

    offset = index * sizeof(date);
    fseek(pfile, offset, SEEK_SET);
    fwrite(record_to_write, sizeof(date), 1, pfile);
    fflush(pfile);
    rewind(pfile);
}

void swap_records_in_file(FILE *pfile, int record_index1, int record_index2) {
    date *record1;
    date *record2;

    record1 = read_record_from_file(pfile, record_index1);
    if (record1 == NULL)
        return;
    record2 = read_record_from_file(pfile, record_index2);
    if (record2 == NULL) {
        free(record1);
        return;
    }
    write_record_in_file(pfile, record1, record_index2);
    write_record_in_file(pfile, record2, record_index1);
    free(record1);
    free(record2);
}

int get_file_size_in_bytes(FILE *pfile) {
    int size;

    fseek(pfile, 0, SEEK_END);
    size = ftell(pfile);
    rewind(pfile);
    return (size);
}

int get_records_count_in_file(FILE *pfile) {
    return (get_file_size_in_bytes(pfile) / sizeof(date));
}

void print_struct(date *record) {
    int count;

    count = 0;
    while (count < (int)(sizeof(date) / sizeof(int))) {
        printf("%d ", *(&record->year + count));
        count++;
    }
    printf("\n");
}
