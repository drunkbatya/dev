// Copyright [2022] <griselle>
#include "data_sort.h"

void sort(double *arr, int num) {
    double temp;
    int count1;

    count1 = 0;
    while (count1 < num - 1) {
        int count2;

        count2 = 0;
        while (count2 < num - count1 - 1) {
            if (arr[count2] > arr[count2 + 1]) {
                temp = arr[count2 + 1];
                arr[count2 + 1] = arr[count2];
                arr[count2] = temp;
            }
            count2++;
        }
        count1++;
    }
}
