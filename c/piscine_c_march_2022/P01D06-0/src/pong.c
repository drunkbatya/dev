// "Copyright [2022] <griselle, lavadama, maddymet>"
// I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI

#include <stdio.h>

#define END_SCORE 21
#define SCREEN_HEIGHT 25
#define SCREEN_WIDTH 80
#define ROCKET_HEIGHT 3
#define ROCKET_SPEED 1

#define ROCKET_SYM 'H'
#define BALL_SYM '$'
#define FIELD_DIVIDER '|'
#define FRAME_SYM '+'

#define LEFT_ROCKET_X 5
#define RIGHT_ROCKET_X (SCREEN_WIDTH - LEFT_ROCKET_X + 1)

#define HALF_ROCKET_SIZE ((ROCKET_HEIGHT - 1) / 2)
#define HALF_SCREEN_SIZE (SCREEN_WIDTH / 2)

void print_start_message(void) {
    printf("\nPress [Space] + [Enter] to start the game and to skip an action.\n");
    printf("([A]/[Z] and [K]/[M]) + [Enter] to move the rackets.\n");
    printf("U need to press [Enter] after typing eatch commands..");
}

void clear_screen(void) {
    printf("\033[H\033[J");
}

void move_cursor(int x, int y) {
    printf("\033[%d;%dH", y, x);
}

void print_rocket(int x, int center_y) {
    int count;
    int y;

    count = 0;
    if ((ROCKET_HEIGHT % 2) == 0) {
        printf("print_rocket error! Height must be an odd number!");
        return;
    }
    y = center_y - HALF_ROCKET_SIZE;
    while (count < ROCKET_HEIGHT) {
        move_cursor(x, y);
        printf("%c", ROCKET_SYM);
        y++;
        count++;
    }
}

int check_rocket_border_y(int y) {
    int top_edge;
    int bottom_edge;

    top_edge = HALF_ROCKET_SIZE + 2;
    bottom_edge = SCREEN_HEIGHT - HALF_ROCKET_SIZE - 1;
    if (y < top_edge)
        return (top_edge);
    if (y > bottom_edge)
        return (bottom_edge);
    return (y);
}

int check_ball_border_y(int y, int direcion) {
    if (y < 3)
        return (-direcion);
    if (y > SCREEN_HEIGHT - 2)
        return (-direcion);
    return (direcion);
}

int check_left_ball_border_x(int ball_x, int ball_y, int rocket_y) {
    if (ball_x < 2)
        return (1);
    if (ball_x == LEFT_ROCKET_X + 1)
        if (ball_y >= (rocket_y - HALF_ROCKET_SIZE) && ball_y <= (rocket_y + HALF_ROCKET_SIZE))
            return (2);
    return (0);
}

int check_right_ball_border_x(int ball_x, int ball_y, int rocket_y) {
    if (ball_x > SCREEN_WIDTH - 1) {
        return (1);
    }
    if (ball_x == RIGHT_ROCKET_X - 1)
        if (ball_y >= (rocket_y - HALF_ROCKET_SIZE) && ball_y <= (rocket_y + HALF_ROCKET_SIZE))
            return (2);
    return (0);
}

void print_ball(int x, int y) {
     move_cursor(x, y);
     printf("%c", BALL_SYM);
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

int check_score(int score_left, int score_right) {
    int x;
    int x_shift;

    if (score_left != END_SCORE && score_right != END_SCORE)
        return (0);
    if (score_left == END_SCORE)
        x_shift = 0;
    if (score_right == END_SCORE)
        x_shift = HALF_SCREEN_SIZE;
    x = ((HALF_SCREEN_SIZE - 16) / 2) + x_shift;
    move_cursor(x, (SCREEN_HEIGHT * 0.33));
    printf("Congratulations!");
    x = ((HALF_SCREEN_SIZE - 8) / 2) + x_shift;
    move_cursor(x, (SCREEN_HEIGHT * 0.33) + 1);
    printf("You WIN!");
    x = ((HALF_SCREEN_SIZE - 22) / 2) + x_shift;
    move_cursor(x, (SCREEN_HEIGHT * 0.33) + 2);
    printf("Press [Enter] to exit!");
    return (1);
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
    int check_ball_border_x_out;
    int check_score_out;

    print_start_message();
    left_rocket_center_y = SCREEN_HEIGHT / 2;
    right_rocket_center_y = SCREEN_HEIGHT / 2;
    ball_x_direction = -1;
    ball_y_direction = -1;
    ball_x = SCREEN_WIDTH / 2;
    ball_y = SCREEN_HEIGHT / 2;
    score_left = 0;
    score_right = 0;
    check_score_out = 0;

    while (1) {
        char sym = getchar();
        if (check_score_out == 1) {
            getchar();
            break;
        }
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

        left_rocket_center_y = check_rocket_border_y(left_rocket_center_y);
        right_rocket_center_y = check_rocket_border_y(right_rocket_center_y);

        ball_y_direction = check_ball_border_y(ball_y, ball_y_direction);

        check_ball_border_x_out = check_left_ball_border_x(ball_x, ball_y, left_rocket_center_y);
        if (check_ball_border_x_out == 1) {
            score_right += 1;
            ball_x = SCREEN_WIDTH / 2;
            ball_y = SCREEN_HEIGHT / 2;
            ball_x_direction = -ball_x_direction;
        }
        if (check_ball_border_x_out == 2)
            ball_x_direction = -ball_x_direction;

        check_ball_border_x_out = check_right_ball_border_x(ball_x, ball_y, right_rocket_center_y);
        if (check_ball_border_x_out == 1) {
            score_left += 1;
            ball_x = SCREEN_WIDTH / 2;
            ball_y = SCREEN_HEIGHT / 2;
            ball_x_direction = -ball_x_direction;
        }
        if (check_ball_border_x_out == 2)
            ball_x_direction = -ball_x_direction;

        print_field_divider();
        print_field_frames();
        print_score(score_left, score_right);
        print_rocket(LEFT_ROCKET_X, left_rocket_center_y);
        print_rocket(RIGHT_ROCKET_X, right_rocket_center_y);
        print_ball(ball_x, ball_y);

        check_score_out = check_score(score_left, score_right);

        move_cursor(1, 1);
    }
    clear_screen();
    return (0);
}
