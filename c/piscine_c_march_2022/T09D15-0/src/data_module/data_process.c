// Copyright [2022] <griselle>
#include "data_process.h"
#include "../data_libs/data_stat.h"
#include <math.h>

int normalization(double *data, int n) {
    double max_value;
    double min_value;
    double size;
    int count;

    count = 0;
    max_value = max(data, n);
    min_value = min(data, n);
    size = max_value - min_value;
    if ((fabs(size) < EPS))
        return (0);
    while (count < n) {
        data[count] = data[count] / size - min_value / size;
        count++;
    }
    return (1);
}
