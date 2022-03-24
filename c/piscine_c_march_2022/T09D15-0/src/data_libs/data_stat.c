// Copyright [2022] <griselle>
#include "./data_stat.h"

double max(double *data, int n) {
    double *new_ptr;
    double out_number;

    new_ptr = data;
    out_number = *new_ptr;
    while (new_ptr - data < n) {
        if (*new_ptr > out_number)
            out_number = *new_ptr;
        new_ptr++;
    }
    return (out_number);
}

double min(double *data, int n) {
    double *new_ptr;
    double out_number;

    new_ptr = data;
    out_number = *new_ptr;
    while (new_ptr - data < n) {
        if (*new_ptr < out_number)
            out_number = *new_ptr;
        new_ptr++;
    }
    return (out_number);
}

double mean(double *data, int n) {
    double *new_ptr;
    double out_number;

    new_ptr = data;
    out_number = 0.0;
    while (new_ptr - data < n) {
        out_number += *new_ptr;
        new_ptr++;
    }
    return (out_number / n);
}

double variance(double *data, int n) {
    double *new_ptr;
    double out_number;
    double mean_value;

    new_ptr = data;
    out_number = 0.0;
    mean_value = mean(data, n);
    while (new_ptr - data < n) {
        out_number += (*new_ptr - mean_value) * (*new_ptr - mean_value);
        new_ptr++;
    }
    return (out_number / n);
}
