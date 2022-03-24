// Copyright [2022] <griselle>

#ifndef SRC_S21_STRING_H_
#define SRC_S21_STRING_H_

unsigned long s21_strlen(const char *str);
int s21_strcmp(const char *str1, const char *str2);
char *s21_strcpy(char *dst, const char *src);
char *s21_strcat(char *str1, const char *str2);
char *s21_strchr(const char *str, int c);
char *s21_strstr(const char *str, const char *substr);
char *s21_strtok(char *str, const char *sep);
#endif  // SRC_S21_STRING_H_
