// Copyright [2022] <griselle>

#include "stack.h"
#include <stdio.h>

#define TEST_NUM 13

int push_test(struct stack **last, int num);
int pop_test(struct stack **last, int num);

int main(void) {
    struct stack *st;

    st = init(4);
    printf("Testing push..");
    if (push_test(&st, TEST_NUM))
        printf("SUCCESS");
    else
        printf("FAIL");
    printf("\nTesting pop..");
    if (pop_test(&st, TEST_NUM))
        printf("SUCCESS");
    else
        printf("FAIL");
    printf("\n");
    destroy(&st);
    return (0);
}

int push_test(struct stack **last, int num) {
    push(last, num);
    if ((*last)->num == num)
        return (1);
    return (0);
}

int pop_test(struct stack **last, int num) {
    if (pop(last) == num)
        return (1);
    return (0);
}
