// Copyright [2022] <griselle>
#include <stdio.h>
#include <stdlib.h>

int get_numbers(int *type, int *size_x, int *size_y);
int dynamic_single_matrix_arr(int size_x, int size_y);
int pointer_array_to_arrays(int size_x, int size_y);
int array_of_pointers(int size_x, int size_y);
int input_dynamic(int **arr, int x, int y);
void output_dynamic(int **arr, int x, int y);
int sorty(int **arr, int x, int y);

int main(void) {
    int type;
    int size_x;
    int size_y;

    if (!get_numbers(&type, &size_x, &size_y)) {
        printf("n/a");
        return (1);
    }
    if (type == 1) {
        if (!dynamic_single_matrix_arr(size_x, size_y)) {
            printf("n/a");
            return (1);
        }
        return (0);
    }
    if (type == 2) {
        if (!pointer_array_to_arrays(size_x, size_y)) {
            printf("n/a");
            return (1);
        }
        return (0);
    }
    if (type == 3) {
        if (!array_of_pointers(size_x, size_y)) {
            printf("n/a");
            return (1);
        }
        return (0);
    }
    return (1);
}

int get_numbers(int *type, int *size_x, int *size_y) {
    char c;

    if (scanf("%d%c", type, &c) != 2)
        return (0);
    if (c != '\n' && c != ' ')
        return (0);
    if (*type < 1 || *type > 3)
        return (0);
    if (scanf("%d%c", size_x, &c) != 2)
        return (0);
    if (c != '\n' && c != ' ')
        return (0);
    if (scanf("%d%c", size_y, &c) != 2)
        return (0);
    if (c != '\n' && c != ' ')
        return (0);
    return (1);
}

int dynamic_single_matrix_arr(int size_x, int size_y) {
    int **arr;
    int *ptr;
    int count;

    count = 0;
    arr = malloc(size_x * size_y * sizeof(int) + size_x * sizeof(int *));
    if (arr == NULL)
        return (0);
    ptr = (int *) (arr + size_x);
    while (count < size_x) {
        *(arr + count) = ptr + size_y * count;
        count++;
    }
    if (!input_dynamic(arr, size_x, size_y)) {
        free(arr);
        return (0);
    }
    if (!sorty(arr, size_x, size_y)) {
        free(arr);
        return (0);
    }
    output_dynamic(arr, size_x, size_y);
    free(arr);
    return (1);
}

int pointer_array_to_arrays(int size_x, int size_y) {
    int **arr;
    int count;

    count = 0;
    arr = malloc(size_x * sizeof(int *));
    if (arr == NULL)
        return (0);
    while (count < size_x) {
        arr[count] = malloc(size_y * sizeof(int));
        if (arr[count] == NULL) {
            free(arr);
            return (0);
        }
        count++;
    }
    count = 0;
    if (!input_dynamic(arr, size_x, size_y)) {
        while (count < size_x) {
            free(arr[count]);
            count++;
        }
        free(arr);
        return (0);
    }
    if (!sorty(arr, size_x, size_y)) {
        free(arr);
        return (0);
    }
    output_dynamic(arr, size_x, size_y);
    while (count < size_x) {
        free(arr[count]);
        count++;
    }
    free(arr);
    return (1);
}

int array_of_pointers(int size_x, int size_y) {
    int **ptr_arr;
    int *val_arr;
    int count;

    count = 0;
    ptr_arr = malloc(size_x * sizeof(int *));
    if (ptr_arr == NULL)
        return (0);
    val_arr = malloc(size_x * size_y * sizeof(int));
    if (val_arr == NULL) {
        free(ptr_arr);
        return (0);
    }
    while (count < size_x) {
        ptr_arr[count] = val_arr + size_y * count;
        count++;
    }
    if (!input_dynamic(ptr_arr, size_x, size_y)) {
        free(ptr_arr);
        free(val_arr);
        return (0);
    }
    if (!sorty(ptr_arr, size_x, size_y)) {
        free(ptr_arr);
        return (0);
    }
    output_dynamic(ptr_arr, size_x, size_y);
    free(ptr_arr);
    free(val_arr);
    return (1);
}

int input_dynamic(int **arr, int x, int y) {
    int count_x;
    char c;

    count_x = 0;
    while (count_x < x) {
        int count_y;

        count_y = 0;
        while (count_y < y) {
            if (count_x == x - 1 && count_y == y - 1) {
                if (scanf("%d", &arr[count_x][count_y]) != 1)
                    return (0);
                if (scanf("%c", &c) != EOF && c != '\n')
                    return (0);
                break;
            }
            if (scanf("%d%c", &arr[count_x][count_y], &c) != 2)
                return (0);
            if (c != ' ' && c != '\n')
                return (0);
            count_y++;
        }
        count_x++;
    }
    return (1);
}

void arr_cpy(const int *arr1, int *arr2, int size) {
    int count;

    count = 0;
    while (count < size) {
        arr2[count] = arr1[count];
        count++;
    }
}

int arr_swap(int *arr1, int *arr2, int size) {
    int *temp_arr_ptr;

    temp_arr_ptr = malloc(size * sizeof(arr1[0]));
    if (temp_arr_ptr == NULL)
        return (0);
    arr_cpy(arr1, temp_arr_ptr, size);
    arr_cpy(arr2, arr1, size);
    arr_cpy(temp_arr_ptr, arr2, size);
    free(temp_arr_ptr);
    return (1);
}

int arr_sum(int *arr, int size) {
    int *new_ptr;
    int sum;

    sum = 0;
    new_ptr = arr;
    while (new_ptr - arr < size) {
        sum += *new_ptr;
        new_ptr++;
    }
    return (sum);
}

int sorty(int **arr, int rows, int y) {
    int count1;

    count1 = 0;
    while (count1 < rows - 1) {
        int count2;

        count2 = 0;
        while (count2 < rows - count1 - 1) {
            if (arr_sum(*(arr + count2), y) > arr_sum(*(arr + count2 + 1), y)) {
                if (!arr_swap(*(arr + count2), *(arr + count2 + 1), y))
                    return (0);
            }
            count2++;
        }
        count1++;
    }
    return (1);
}

void output_dynamic(int **arr, int x, int y) {
    int count_x;

    count_x = 0;
    while (count_x < x) {
        int count_y;

        count_y = 0;
        while (count_y < y) {
            printf("%d", arr[count_x][count_y]);
            if (count_y < y - 1)
                printf(" ");
            else
                printf("\n");
            count_y++;
        }
        count_x++;
    }
}
