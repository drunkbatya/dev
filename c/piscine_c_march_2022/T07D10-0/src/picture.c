#include <stdio.h>

#define N 15
#define M 13

void transform(int matr[N][M], int *buf[N], int n);
void make_picture(int *picture[N], int n, int m);
void reset_picture(int *picture[N], int n, int m);
void output(int *arr[N], int n, int m);

int main(void) {
    int picture_data[N][M];
    int *picture[N];

    transform(picture_data, picture, N);
    make_picture(picture, N, M);
    output(picture, N, M);
    return (0);
}

void draw_frame_w(int *picture[N], int arr[], int size, int h) {
    int count;

    count = 0;
    while (count < size) {
        *(picture[0] + count) = *(arr + count);
        *(picture[(h - 1) / 2] + count) = *(arr + count);
        *(picture[h - 1] + count) = *(arr + count);
        count++;
    }
}

void draw_frame_h(int *picture[N], int arr[], int size, int w) {
    int count;

    count = 0;
    while (count < size) {
        *picture[count] = *(arr + count);
        *(picture[count] + (w - 1) / 2) = *(arr + count);
        *(picture[count] + (w - 1)) = *(arr + count);
        count++;
    }
}

void draw_trunk(int *picture[N], int arr[], int size) {
    int count;

    count = 0;
    while (count < size) {
        *(picture[6 + count] + 3) = *(arr + count);
        *(picture[6 + count] + 4) = *(arr + count);
        *(picture[10] + count + 2) = *(arr + count);
        count++;
    }
}

void draw_foliage(int *picture[N], int arr[], int size) {
    int count;

    count = 0;
    while (count < size) {
        *(picture[3] + count + 2) = *(arr + count);
        *(picture[4] + count + 2) = *(arr + count);
        *(picture[2 + count] + 3) = *(arr + count);
        *(picture[2 + count] + 4) = *(arr + count);
        count++;
    }
}

void draw_sun(int *picture[N], int arr[6][5], int arr_size_x, int arr_size_y) {
    int count1;

    count1 = 0;
    while (count1 < arr_size_y) {
        int count2;

        count2 = 0;
        while (count2 < arr_size_x) {
            *(picture[1 + count1] + 7 + count2) = *(arr[count1] + count2);
            count2++;
        }
        count1++;
    }
}

void make_picture(int *picture[N], int n, int m) {
    int frame_w[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int frame_h[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    int tree_trunk[] = { 7, 7, 7, 7 };
    int tree_foliage[] = { 3, 3, 3, 3 };
    int sun_data[6][5] = { { 0, 6, 6, 6, 6 },
                           { 0, 0, 6, 6, 6 },
                           { 0, 0, 6, 6, 6 },
                           { 0, 6, 0, 0, 6 },
                           { 0, 0, 0, 0, 0 },
                           { 0, 0, 0, 0, 0 } };

    reset_picture(picture, n, m);

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);
    int length_turnk = sizeof(tree_trunk) / sizeof(tree_trunk[0]);
    int length_foliage = sizeof(tree_foliage) / sizeof(tree_foliage[0]);
    int length_sun_x = sizeof(sun_data) / sizeof(sun_data[0]);
    int length_sun_y = sizeof(sun_data[0]) / sizeof(sun_data[0][0]);

    draw_trunk(picture, tree_trunk, length_turnk);
    draw_foliage(picture, tree_foliage, length_foliage);
    draw_sun(picture, sun_data, length_sun_x, length_sun_y);
    draw_frame_w(picture, frame_w, length_frame_w, length_frame_h);
    draw_frame_h(picture, frame_h, length_frame_h, length_frame_w);
}

void reset_picture(int *picture[N], int n, int m) {
    int count_n;

    count_n = 0;
    while (count_n < n) {
        int count_m;

        count_m = 0;
        while (count_m < m) {
             *(picture[count_n] + count_m) = 0;
             count_m++;
        }
        count_n++;
    }
}

void transform(int matr[N][M], int *buf[N], int n) {
    int count;

    count = 0;
    while (count < n) {
        buf[count] = &matr[count][0];
        count++;
    }
}

void output(int *arr[N], int n, int m) {
    int count_x;

    count_x = 0;
    while (count_x < n) {
        int count_y = 0;
        while (count_y < m) {
            printf("%d", *(arr[count_x] + count_y));
            if (count_y < m - 1)
                printf(" ");
            else if (count_x != n - 1)
                printf("\n");
            count_y++;
        }
        count_x++;
    }
}
