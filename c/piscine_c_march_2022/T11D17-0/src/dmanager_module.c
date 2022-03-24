// Copyright [2022] <griselle>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void close_doors(struct door *doors);
void printf_doors(struct door *doors);

int main(void) {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    close_doors(doors);
    printf_doors(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void close_doors(struct door *doors) {
    int count;

    count = 0;
    while (count < DOORS_COUNT) {
        doors[count].status = 0;
        count++;
    }
}

void printf_doors(struct door *doors) {
    int count;

    count = 0;
    while (count < DOORS_COUNT) {
        printf("%d, ", doors[count].id);
        printf("%d", doors[count].status);
        if (count < DOORS_COUNT - 1)
            printf("\n");
        count++;
    }
}
