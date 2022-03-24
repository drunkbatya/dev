// Copyright [2022] <griselle>
#include <stdio.h>
#include <stdlib.h>
#include "decision.h"
#include "../data_libs/data_io.h"

int main(void) {
    double *data;
    int n;

    data = NULL;
    if (!input(&data, &n)) {
        printf("n/a");
        if (data != NULL)
            free(data);
        return (1);
    }
    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");
    free(data);
    return(0);
}
