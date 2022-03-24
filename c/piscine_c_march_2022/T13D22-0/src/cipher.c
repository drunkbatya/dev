// Copyright [2022] <griselle>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "logger.h"

int read_string(char **str);
int make_me_free(char *filename, char *text, FILE *file_ptr, char *dirpath, int exit_code);
int read_cmd(int *cmd);
int menu(char **filename, char **text, FILE **file_ptr, char **dirpath, int *shift);
int open_file(char *str, FILE **file_ptr, char *mode);
void print_text_from_file(FILE *file_ptr);
void put_text_to_file(FILE *file_ptr, char *text);
int read_string(char **str);
int cesar_empty_cmd(char **dirpath, int shift);

int main(void) {
    char *filename;
    char *text;
    char *dirpath;
    FILE *file_ptr;
    int shift;

    filename = NULL;
    text = NULL;
    dirpath = NULL;
    file_ptr = NULL;

    #ifdef LOG
    FILE *log = log_init("log.log");
    logcat(log, "program started", info);
    log_close(log);
    #endif

    if (!menu(&filename, &text, &file_ptr, &dirpath, &shift)) {
        printf("n/a");
        return (make_me_free(filename, text, file_ptr, dirpath, 1));
    }

    #ifdef LOG
    log = log_init("log.log");
    logcat(log, "program ended", info);
    log_close(log);
    #endif
    return (make_me_free(filename, text, file_ptr, dirpath, 0));
}

int make_me_free(char *filename, char *text, FILE *file_ptr, char *dirpath, int exit_code) {
    if (text)
        free(text);
    if (filename)
        free(filename);
    if (file_ptr)
        fclose(file_ptr);
    if (dirpath)
        free(dirpath);
    return (exit_code);
}

int read_str_cmd(char **filename, FILE **file_ptr) {
    if (!read_string(filename))
        return (0);
    if (!open_file(*filename, file_ptr, "r")) {
        printf("n/a\n");
        return (-1);
    }
    print_text_from_file(*file_ptr);
    return (-1);
}

int write_cmd(char **filename, char **text, FILE **file_ptr) {
    if (!read_string(text))
        return (0);
    if (*file_ptr == NULL) {
        if (*text) {
            free(*text);
            *text = NULL;
        }
        printf("n/a\n");
        return (-1);
    }
    if (!open_file(*filename, file_ptr, "a")) {
        printf("n/a\n");
        return (-1);
    }
    put_text_to_file(*file_ptr, *text);
    if (!open_file(*filename, file_ptr, "r")) {
        printf("n/a\n");
        return (-1);
    }
    print_text_from_file(*file_ptr);
    return (-1);
}

int menu(char **filename, char **text, FILE **file_ptr, char **dirpath, int *shift) {
    int cmd;
    int cmd_out;

    #ifdef LOG
    FILE *log = log_init("log.log");
    #endif
    cmd = 0;
    while (1) {
        if (!read_cmd(&cmd))
            return (0);
        if (cmd == -1)
            return (1);
        if (cmd == 1) {
            #ifdef LOG
            logcat(log, "cmd = 1", debug);
            #endif
            cmd_out = read_str_cmd(filename, file_ptr);
            if (cmd_out == -1)
                continue;
            if (cmd_out == 0)
                return (0);
        }
        if (cmd == 2) {
            #ifdef LOG
            logcat(log, "cmd = 2", debug);
            #endif
            cmd_out = write_cmd(filename, text, file_ptr);
            if (cmd_out == -1)
                continue;
            if (cmd_out == 0)
                return (0);
        }
        if (cmd == 3) {
            #ifdef LOG
            logcat(log, "cmd = 3", debug);
            #endif
            if (!read_cmd(shift))
                return (0);
            cmd_out = cesar_empty_cmd(dirpath, *shift);
            if (cmd_out == -1)
                continue;
            if (cmd_out == 0)
                return (0);
        }
        return (0);
    }
    #ifdef LOG
    log_close(log);
    #endif
}

void get_empty(char *str) {
    FILE *temp;

    if (!str)
        return;
    if (strcmp((str + strlen(str) - 2), ".h") != 0)
        return;
    temp = fopen(str, "w");
    if (temp == NULL)
        return;
    fclose(temp);
}

char *str_join(char *str1, char *str2) {
    char *out;

    out = malloc(strlen(str1) + strlen(str2) + 1);
    if (out == NULL)
        return (NULL);
    strcpy(out, str1);
    strcat(out, str2);
    return (out);
}

unsigned long filelen(char *full_path) {
    unsigned long len;
    FILE *temp;
    int c;

    len = 0;
    temp = fopen(full_path, "r");
    c = getc(temp);
    while (c != EOF) {
        len++;
        c = getc(temp);
    }
    fclose(temp);
    return (len);
}

char cesar(char c, int shift) {
    int count;

    if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
        return (c);
    count = 0;
    while (count < shift) {
        if (c == 'z')
            c = 'a';
        else if (c == 'Z')
            c = 'A';
        else
            c++;
        count++;
    }
    if (shift >= 0)
        return (c);
    shift = -shift;
    count = 0;
    while (count < shift) {
        if (c == 'a')
            c = 'z';
        else if (c == 'A')
            c = 'Z';
        else
            c--;
        count++;
    }
    return (c);
}

void cesar_cpy(char *ptr, char *full_path, int shift) {
    FILE *temp;
    int c;

    temp = fopen(full_path, "r");
    c = getc(temp);
    while (c != EOF) {
        *ptr = cesar(c, shift);
        c = getc(temp);
        ptr++;
    }
    fclose(temp);
}

void cesar_salad(char *full_path, int shift) {
    #ifdef LOG
    FILE *log = log_init("log.log");
    logcat(log, "applying cesar cipher", info);
    log_close(log);
    #endif
    char *temp_ptr;
    FILE *temp;

    if (!full_path)
        return;
    if (strcmp((full_path + strlen(full_path) - 2), ".c") != 0)
        return;
    temp_ptr = malloc(filelen(full_path) + 1);
    if (temp_ptr == NULL)
        return;
    cesar_cpy(temp_ptr, full_path, shift);
    temp = fopen(full_path, "w");
    if (temp == NULL)
        return;
    put_text_to_file(temp, temp_ptr);
    fclose(temp);
    free(temp_ptr);
    return;
}

int cesar_empty_cmd(char **dirpath, int shift) {
    DIR *dir_ptr;
    struct dirent *s_dir;

    if (!read_string(dirpath))
        return (0);
    dir_ptr = opendir(*dirpath);
    if (dir_ptr == NULL)
        return (0);
    s_dir = readdir(dir_ptr);
    while (s_dir != NULL) {
        char *full_path;

        full_path = str_join(*dirpath, s_dir->d_name);
        get_empty(full_path);
        cesar_salad(full_path, shift);
        s_dir = readdir(dir_ptr);
        if (full_path)
            free(full_path);
    }
    closedir(dir_ptr);
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

void print_text_from_file(FILE *file_ptr) {
    int c;

    c = getc(file_ptr);
    if (c == EOF) {
        printf("n/a\n");
        return;
    }
    while (c != EOF) {
        putchar(c);
        c = getc(file_ptr);
    }
    putchar('\n');
}

void put_text_to_file(FILE *file_ptr, char *text) {
    while (*text != '\0') {
        putc(*text, file_ptr);
        text++;
    }
    putc(*text, file_ptr);
}

int read_cmd(int *cmd) {
    int c;

    c = getchar();
    if (c == '-') {
        if (getchar() == '1') {
            *cmd = -1;
            return (1);
        } else {
            return (0);
        }
    }
    if (c < '0' || c > '9')
        return (0);
    *cmd = c - '0';
    c = getchar();
    if (c == '\n' || c == ' ')
        return (1);
    return (0);
}

int read_string(char **str) {
    int c;

    *str = calloc(1, sizeof(char));
    if (*str == NULL)
        return (0);
    c = getchar();
    while (c != EOF && c != '\n' && c != ' ') {
        *str = realloc(*str, (strlen(*str) + 2));
        if (*str == NULL)
            return (0);
        *(*str + strlen(*str)) = c;
        c = getchar();
    }
    if (!strlen(*str))
        return (0);
    // *(*str + sizeof(*str)) = '\0';
    return (1);
}
