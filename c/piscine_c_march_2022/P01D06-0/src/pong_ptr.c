// "Copyright [2022] <griselle, lavadama, maddymet>"
// I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI

#include <stdio.h>
// #include <stdlib.h>

#define SCREEN_HEIGHT 25
#define SCREEN_WIDTH 80
#define ROCKET_HEIGHT 3
#define ROCKET_SPEED 2

#define ROCKET_SYM 'H'
#define BALL_SYM '$'
#define FIELD_DIVIDER '|'
#define FRAME_SYM '+'

#define LEFT_ROCKET_X 3
#define RIGHT_ROCKET_X (SCREEN_WIDTH - LEFT_ROCKET_X + 1)

#define HALF_ROCKET_SIZE ((ROCKET_HEIGHT - 1) / 2)

void check_rocket_border_y(int *y);
void set_ball_center(int *x, int *y, int *direction);

void print_start_message(void) {
    printf("\nPress [Space] + [Enter] to start the game and to skip an action at a certain step.\n");
    printf("([A]/[Z] and [K]/[M]) + [Enter] to move the rackets.\n");
    printf("U need to press [Enter] after typing eatch commands..");
}

void clear_screen(void) {
    printf("\033[H\033[J");
}

void move_cursor(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void print_rocket(int x, int y) {
    int count;

    count = 0;
    y = y - HALF_ROCKET_SIZE;
    if ((ROCKET_HEIGHT % 2) == 0) {
        printf("print_rocket error! Height must be an odd number!");
        return;
    }
    while (count < ROCKET_HEIGHT) {
        move_cursor(x, y);
        printf("%c", ROCKET_SYM);
        y++;
        count++;
    }
}

void check_rocket_border_y(int *y) {
    int top_edge;
    int bottom_edge;

    top_edge = HALF_ROCKET_SIZE + 2;
    bottom_edge = SCREEN_HEIGHT - HALF_ROCKET_SIZE - 1;
    if (*y < top_edge)
        *y = top_edge;
    if (*y > bottom_edge)
        *y = bottom_edge;
}

void check_ball_border_y(int ball_y, int *direcion) {
    if (ball_y < 3)
        *direcion = -*direcion;
    if (ball_y > SCREEN_HEIGHT - 2)
        *direcion = -*direcion;
}

void check_left_ball_border_x(int *ball_x, int *ball_y, int rocket_y, int *direction, int *score_right) {
    if (*ball_x < LEFT_ROCKET_X - 1) {
        *score_right += 1;
        set_ball_center(ball_x, ball_y, direction);
    }
    if (*ball_x == LEFT_ROCKET_X + 1)
        if (*ball_y >= (rocket_y - HALF_ROCKET_SIZE) && *ball_y <= (rocket_y + HALF_ROCKET_SIZE))
            *direction = -*direction;
}

void check_right_ball_border_x(int *ball_x, int *ball_y, int rocket_y, int *direction, int *score_left) {
    if (*ball_x > RIGHT_ROCKET_X + 1) {
        *score_left += 1;
        set_ball_center(ball_x, ball_y, direction);
    }
    if (*ball_x == RIGHT_ROCKET_X - 1)
        if (*ball_y >= (rocket_y - HALF_ROCKET_SIZE) && *ball_y <= (rocket_y + HALF_ROCKET_SIZE))
            *direction = -*direction;
}

void print_ball(int x, int y) {
     move_cursor(x, y);
     printf("%c", BALL_SYM);
}

void set_ball_center(int *x, int *y, int *direction) {
    *x = SCREEN_WIDTH / 2;
    *y = SCREEN_HEIGHT / 2;
    *direction = -*direction;
}

void print_field_divider(void) {
    int count;

    count = 0;
    while (count < SCREEN_HEIGHT) {
        move_cursor((SCREEN_WIDTH / 2), count);
        printf("%c", FIELD_DIVIDER);
        count++;
    }
}

void print_field_frames(void) {
    int count;

    count = 0;
    while (count < SCREEN_WIDTH + 1) {
         move_cursor(count, 1);
         printf("%c", FRAME_SYM);
         move_cursor(count, SCREEN_HEIGHT);
         printf("%c", FRAME_SYM);
         count++;
    }
    count = 0;
    while (count < SCREEN_HEIGHT + 1) {
         move_cursor(1, count);
         printf("%c", FRAME_SYM);
         move_cursor(SCREEN_WIDTH, count);
         printf("%c", FRAME_SYM);
         count++;
    }
}

void print_score(int score_left, int score_right) {
    int score_left_x_shift;

    score_left_x_shift = 2;
    if (score_left > 9)
        score_left_x_shift = 3;
    move_cursor((SCREEN_WIDTH / 2) - score_left_x_shift, (SCREEN_HEIGHT * 0.1));
    printf("%d", score_left);
    move_cursor((SCREEN_WIDTH / 2) + 2, (SCREEN_HEIGHT * 0.1));
    printf("%d", score_right);
}

int main(void) {
    int left_rocket_center_y;
    int right_rocket_center_y;
    int ball_x;
    int ball_y;
    int ball_x_direction;
    int ball_y_direction;
    int score_left;
    int score_right;
    char sym;

    print_start_message();
    //system("/bin/stty raw");
    left_rocket_center_y = SCREEN_HEIGHT / 2;
    right_rocket_center_y = SCREEN_HEIGHT / 2;
    ball_x_direction = -1;
    ball_y_direction = -1;
    score_left = 0;
    score_right = 0;
    set_ball_center(&ball_x, &ball_y, &ball_x_direction);
    while (1) {
        sym = getchar();
        // if score break;
        if (sym == 'a')
            left_rocket_center_y -= ROCKET_SPEED;
        if (sym == 'z')
            left_rocket_center_y += ROCKET_SPEED;
        if (sym == 'k')
            right_rocket_center_y -= ROCKET_SPEED;
        if (sym == 'm')
            right_rocket_center_y += ROCKET_SPEED;
        if (sym != 'a' && sym != 'z' && sym!= 'k' && sym != 'm' && sym != ' ') {
            move_cursor(1, 1);
            continue;
        }
        ball_x = ball_x + ball_x_direction;
        ball_y = ball_y + ball_y_direction;
        clear_screen();

        check_rocket_border_y(&left_rocket_center_y);
        check_rocket_border_y(&right_rocket_center_y);

        check_ball_border_y(ball_y, &ball_y_direction);

        check_left_ball_border_x(&ball_x, &ball_y, left_rocket_center_y, &ball_x_direction, &score_right);
        check_right_ball_border_x(&ball_x, &ball_y, right_rocket_center_y, &ball_x_direction, &score_left);

        print_field_divider();
        print_field_frames();
        print_score(score_left, score_right);
        print_rocket(LEFT_ROCKET_X, left_rocket_center_y);
        print_rocket(RIGHT_ROCKET_X, right_rocket_center_y);
        print_ball(ball_x, ball_y);

        move_cursor(1, 1);
    }
    clear_screen();
    //system("/bin/stty cooked");
    return (0);
}
