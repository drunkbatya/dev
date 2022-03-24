// "Copyright [2022] <jaint **arr, int x, int y1unewayj, griselle, rambtono>"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  // for sleep() function only
#include <sys/ioctl.h>  // for kbhit() function only

#define GAME_SPEED_CONST 70000  // ms / 100

#define SCREEN_HEIGHT 25
#define SCREEN_WIDTH 80

#define DEATH 0
#define LIFE 1
#define FRAME 9

#define FRAME_SYM '#'
#define LIFE_SYM '*'

#define LIFE_COLOR "\033[0;32m"
#define DEATH_COLOR "\033[0;31m"
#define NO_COLOR "\033[0m"

int parse_control_keyboard(int *game_speed);
void clear_screen(void);
int **create_matrix(int size_x, int size_y);
void clear_matrix(int **arr, int x, int y);
void copy_matrix(int **ptr1, int **ptr2, int x, int y);
void add_frames_to_matrix(int **arr, int x, int y);
void print_matrix(int **arr, int x, int y);
int read_initial_state(int **arr, int x, int y);
void life(int **ptr_cur, int **ptr_next, int x, int y);
int compare_matrix(int **ptr1, int **ptr2, int x, int y);
unsigned int crc32(int **arr, int x, int y);

int main(void) {
    int **ptr_cur;
    int **ptr_next;
    int game_speed;

    game_speed = 5;
    ptr_cur = create_matrix(SCREEN_HEIGHT, SCREEN_WIDTH);
    ptr_next = create_matrix(SCREEN_HEIGHT, SCREEN_WIDTH);
    if (ptr_cur == NULL || ptr_next == NULL) {
        printf("Memmory allocation error!.. :-(");
        if (ptr_cur != NULL)
            free(ptr_cur);
        if (ptr_next != NULL)
            free(ptr_next);
        return (1);
    }
    if (!read_initial_state(ptr_cur, SCREEN_HEIGHT, SCREEN_WIDTH)) {
        printf("Failed to load config.. :-(");
        free(ptr_cur);
        free(ptr_next);
        return (1);
    }
    if (freopen("/dev/tty", "r", stdin) == NULL) {
        printf("Failed to connect to terminal.. :-(");
        free(ptr_cur);
        free(ptr_next);
        return (1);
    }
    while (1) {
        if (!parse_control_keyboard(&game_speed))
            break;
        clear_screen();
        print_matrix(ptr_cur, SCREEN_HEIGHT, SCREEN_WIDTH);
        printf("[Control: [Z] - speed down, [X] - speed up, [Q] - exit]");
        printf("[Current speed: %d]\n", 10 - game_speed);
        printf("CRC: %d\n", crc32(ptr_next, SCREEN_HEIGHT, SCREEN_WIDTH));
        clear_matrix(ptr_next, SCREEN_HEIGHT, SCREEN_WIDTH);
        life(ptr_cur, ptr_next, SCREEN_HEIGHT, SCREEN_WIDTH);
        if (compare_matrix(ptr_cur, ptr_next, SCREEN_HEIGHT, SCREEN_WIDTH)) {
            printf(DEATH_COLOR"DEATH..\n"NO_COLOR);
            break;
        }
        clear_matrix(ptr_cur, SCREEN_HEIGHT, SCREEN_WIDTH);
        copy_matrix(ptr_next, ptr_cur, SCREEN_HEIGHT, SCREEN_WIDTH);
        add_frames_to_matrix(ptr_cur, SCREEN_HEIGHT, SCREEN_WIDTH);
        usleep(game_speed * GAME_SPEED_CONST);
    }
    free(ptr_cur);
    free(ptr_next);
    return(0);
}

int kbhit(void) {
    int bytes_ready;

    ioctl(1, FIONREAD, &bytes_ready);
    return (bytes_ready);
}

int parse_control_keyboard(int *game_speed) {
    system("/bin/stty raw");
    if (kbhit()) {
        int c;

        c = getchar();
        if (c == 'z')
            *game_speed += 1;
        if (c == 'x')
            *game_speed -= 1;
        if (c == 'q') {
            system("/bin/stty cooked");
            return (0);
        }
    }
    if (*game_speed < 1)
        *game_speed = 1;
    if (*game_speed > 9)
        *game_speed = 9;
    system("/bin/stty cooked");
    return (1);
}

void clear_screen(void) {
    printf("\033[H\033[J");
}

int **create_matrix(int size_x, int size_y) {
    int **arr;
    int *ptr;

    arr = malloc(size_x * size_y * sizeof(int) + size_x * sizeof(int *));
    if (arr == NULL)
        return (arr);
    ptr = (int *) (arr + size_x);
    for (int count = 0; count < size_x; count++)
        *(arr + count) = ptr + size_y * count;
    clear_matrix(arr, size_x, size_y);
    return (arr);
}

void clear_matrix(int **arr, int x, int y) {
    for (int count_x = 0; count_x < x; count_x++)
        for (int count_y = 0; count_y < y; count_y++)
            arr[count_x][count_y] = 0;
}

void copy_matrix(int **ptr1, int **ptr2, int x, int y) {
    for (int count_x = 0; count_x < x; count_x++)
        for (int count_y = 0; count_y < y; count_y++)
            ptr2[count_x][count_y] = ptr1[count_x][count_y];
}

int compare_matrix(int **ptr1, int **ptr2, int x, int y) {
    for (int count_x = 0; count_x < x; count_x++)
        for (int count_y = 0; count_y < y; count_y++)
            if (ptr2[count_x][count_y] != ptr1[count_x][count_y])
                return (0);
    return (1);
}

void print_matrix(int **arr, int x, int y) {
    for (int count_x = 0; count_x < x; count_x++) {
        for (int count_y = 0; count_y < y; count_y++) {
            if (arr[count_x][count_y] == FRAME)
                printf("%c", FRAME_SYM);
            else if (arr[count_x][count_y] == LIFE)
                printf(LIFE_COLOR"%c"NO_COLOR, LIFE_SYM);
            else
                printf(" ");
            if (count_y == y - 1)
                printf("\n");
        }
    }
}

void add_frames_to_matrix(int **arr, int x, int y) {
    for (int count_y = 0; count_y < y; count_y++) {
        arr[0][count_y] = FRAME;
        arr[x - 1][count_y] = FRAME;
    }
    for (int count_x = 0; count_x < x; count_x++) {
        arr[count_x][0] = FRAME;
        arr[count_x][y - 1] = FRAME;
    }
}

int read_initial_state(int **arr, int x, int y) {
    int count_x;
    int c;

    count_x = 0;
    while (count_x < x) {
        int count_y;

        count_y = 0;
        while (count_y < y) {
            c = getchar();
            if (c == '\n')
                continue;
            if ((c < '0') || (c > '9'))
                return (0);
            arr[count_x][count_y] = c - '0';
            count_y++;
        }
        count_x++;
    }
    c = getchar();
    if (c == EOF)
        return (1);
    if (c == '\n')
        if (getchar() != EOF)
            return (0);
    return (1);
}

int neighborhood_count(int **arr, int row, int col, int x, int y) {
    int act_row;
    int act_col;
    int sum;

    sum = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        if (i == 0)
            act_row = x - 2;
        else if (i == x - 1)
            act_row = 1;
        else
            act_row = i;
        for (int j = col - 1; j <= col + 1; j++) {
            if (j == 0)
                act_col = y - 2;
            else if (j == y - 1)
                act_col = 1;
            else
                act_col = j;
            if (i == row && j == col)
                continue;
            sum += arr[act_row][act_col];
        }
    }
    return (sum);
}

void life(int **ptr_cur, int **ptr_next, int x, int y) {
    for (int count_x = 0; count_x < x; count_x++) {
        for (int count_y = 0; count_y < y; count_y++) {
            int cell_neighborhood_count;

            if (count_y < 1 || count_x < 1) {
                ptr_next[count_x][count_y] = ptr_cur[count_x][count_y];
                continue;
            }
            if (count_y > y - 2 || count_x > x - 2) {
                ptr_next[count_x][count_y] = ptr_cur[count_x][count_y];
                continue;
            }
            cell_neighborhood_count = neighborhood_count(ptr_cur, count_x, count_y, x, y);
            if (ptr_cur[count_x][count_y] == DEATH) {
                if (cell_neighborhood_count == 3)
                    ptr_next[count_x][count_y] = LIFE;
            }
            if (ptr_cur[count_x][count_y] == LIFE) {
                if (cell_neighborhood_count == 2) {
                    ptr_next[count_x][count_y] = LIFE;
                    continue;
                }
                if (cell_neighborhood_count == 3) {
                    ptr_next[count_x][count_y] = LIFE;
                    continue;
                }
                ptr_next[count_x][count_y] = DEATH;
            }
        }
    }
}

unsigned int crc32(int **arr, int x, int y) {
    unsigned int out;
    unsigned int mask;

    out = 0xFFFFFFFF;
    for (int count_x = 0; count_x < x; count_x++) {
        for (int count_y = 0; count_y < y; count_y++) {
            out = out ^ arr[count_x][count_y];
            for (int i = 7; i >= 0; i--) {
                mask = -(out & 1);
                out = (out >> 1) ^ (0xEDB88320 & mask);
            }
        }
    }
    return (~out);
}
