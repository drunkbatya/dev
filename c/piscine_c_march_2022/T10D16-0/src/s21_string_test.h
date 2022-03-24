// Copyright [2022] <griselle>
#ifndef SRC_S21_STRING_TEST_H_
#define SRC_S21_STRING_TEST_H_

void s21_strlen_test(const char *str, unsigned long true_size);
void s21_strcmp_test(const char *str1, const char *str2, int expect_value);
void s21_strcpy_test(const char *str1, char *str2, int expect_cmp_result);
void s21_strcat_test(const char *str1, char *str2, unsigned long expect_len_result);
void s21_strchr_test(char *str, const int c, const char *expected_ptr);
void s21_strstr_test(const char *str, const char *substr, const char *expected_ptr);
void s21_strtok_test(char *str, const char *sep, const char *expected_str);
#endif  // SRC_S21_STRING_TEST_H_
