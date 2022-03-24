// Copyright [2022] <griselle>
#include <stdio.h>

int my_strlen(char *str) {
    int len;

    len = 0;
    while (*str++)
        len++;
    return (len);
}

int my_strcmp(char *str1, char *str2) {
    int count;

    count = 0;
    if (my_strlen(str1) != my_strlen(str2))
        return (0);
    while (count < my_strlen(str1))
        if (*str1++ != *str2++)
            return (0);
    return (1);
}

int parse_single_hex(char sym) {
    if (sym >= '0' && sym <= '9')
        return (sym - '0');
    if (sym >= 'A' && sym <= 'F')
        return ((sym - 'A') + 10);
    if (sym >= 'a' && sym <= 'f')
        return ((sym - 'a') + 10);
    return (-1);
}

int print_hex_to_char(void) {
    int first;
    int second;
    int space;

    first = parse_single_hex(getchar());
    if (first == -1)
        return (-1);
    second = parse_single_hex(getchar());
    if (second == -1)
        return (-1);
    space = getchar();
    if (first < 0 || second < 0)
        return (-1);
    if (space != '\n' && space != ' ')
        return (-1);
    printf("%c", (first << 4) + second);
    if (space == ' ') {
        printf(" ");
        return (1);
    }
    if (space == '\n')
        return (0);
    return (-1);
}

int print_char_to_hex(void) {
    int cchar;
    int space;

    cchar = getchar();
    if (cchar == -1)
        return (-1);
    space = getchar();
    if (cchar < 0)
        return (-1);
    if (space != '\n' && space != ' ')
        return (-1);
    printf("%02X", cchar);
    if (space == ' ') {
        printf(" ");
        return (1);
    }
    if (space == '\n')
        return (0);
    return (-1);
}

int decode(void) {
    int print_status;
    while (1) {
        print_status = print_hex_to_char();
        if (print_status < 0) {
            printf("n/a");
            return (1);
        }
        if (print_status == 0)
            break;
    }
    return (0);
}

int encode(void) {
    int print_status;
    while (1) {
        print_status = print_char_to_hex();
        if (print_status < 0) {
            printf("n/a");
            return (1);
        }
        if (print_status == 0)
            break;
    }
    return (0);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        printf("n/a");
        return (1);
    }
    if (my_strcmp(argv[1], "0")) {
        return (encode());
    }
    if (my_strcmp(argv[1], "1")) {
        return (decode());
    }
    printf("n/a");
    return (1);
}
