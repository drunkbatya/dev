// Copyright [2022] <griselle>
#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 100

int get_numbers(int *type, int *size_x, int *size_y);
int static_arr(int size_x, int size_y);
int dynamic_single_matrix_arr(int size_x, int size_y);
int pointer_array_to_arrays(int size_x, int size_y);
int array_of_pointers(int size_x, int size_y);
int input_static(int arr[ARR_SIZE][ARR_SIZE], int x, int y);
void output_static(int arr[ARR_SIZE][ARR_SIZE], int x, int y);
int input_dynamic(int **arr, int x, int y);
void output_dynamic(int **arr, int x, int y);

int main(void) {
    int type;
    int size_x;
    int size_y;

    if (!get_numbers(&type, &size_x, &size_y)) {
        printf("n/a");
        return (1);
    }
    if (type == 1) {
        if (!static_arr(size_x, size_y)) {
            printf("n/a");
            return (1);
        }
        return (0);
    }
    if (type == 2) {
        if (!dynamic_single_matrix_arr(size_x, size_y)) {
            printf("n/a");
            return (1);
        }
        return (0);
    }
    if (type == 3) {
        if (!pointer_array_to_arrays(size_x, size_y)) {
            printf("n/a");
            return (1);
        }
        return (0);
    }
    if (type == 4) {
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
    if (*type < 1 || *type > 4)
        return (0);
    if (scanf("%d%c", size_x, &c) != 2)
        return (0);
    if (c != '\n' && c != ' ')
        return (0);
    if (*type == 1 && *size_x > ARR_SIZE)
        return (0);
    if (scanf("%d%c", size_y, &c) != 2)
        return (0);
    if (c != '\n' && c != ' ')
        return (0);
    if (*type == 1 && *size_y > ARR_SIZE)
        return (0);
    return (1);
}

int static_arr(int size_x, int size_y) {
    int static_arr[ARR_SIZE][ARR_SIZE];

    if (!input_static(static_arr, size_x, size_y))
        return (0);
    output_static(static_arr, size_x, size_y);
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
    output_dynamic(ptr_arr, size_x, size_y);
    free(ptr_arr);
    free(val_arr);
    return (1);
}

int input_static(int arr[ARR_SIZE][ARR_SIZE], int x, int y) {
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

void output_static(int arr[ARR_SIZE][ARR_SIZE], int x, int y) {
    int count_x;

    count_x = 0;
    while (count_x < x) {
        int count_y = 0;
        while (count_y < y) {
            printf("%d", arr[count_x][count_y]);
            if (count_y < y - 1)
                printf(" ");
            else if (count_x != x - 1)
                printf("\n");
            count_y++;
        }
        count_x++;
    }
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

void output_dynamic(int **arr, int x, int y) {
    int count_x;

    count_x = 0;
    while (count_x < x) {
        int count_y = 0;
        while (count_y < y) {
            printf("%d", arr[count_x][count_y]);
            if (count_y < y - 1)
                printf(" ");
            else if (count_x != x - 1)
                printf("\n");
            count_y++;
        }
        count_x++;
    }
}
