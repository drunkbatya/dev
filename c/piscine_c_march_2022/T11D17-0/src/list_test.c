// Copyright [2022] <griselle>

#include <stdio.h>
#include "door_struct.h"
#include <stdlib.h>
#include "list.h"

int add_door_test(struct node *elem, struct door *door);
int remove_door_test(struct node *elem, struct node *root);

int main(void) {
    struct door one;
    struct door two;
    struct node *li;

    one.id = 1;
    one.status = 0;
    two.id = 2;
    two.status = 1;
    li = init(&one);
    printf("Testing add_door..");
    if (add_door_test(li, &two))
        printf("SUCCESS");
    else
        printf("FAIL");
    printf("\nTesting remove_door..");
    if (remove_door_test(find_door(two.id, li), li))
        printf("SUCCESS");
    else
        printf("FAIL");
    printf("\n");
    destroy(li);
    return (0);
}

int add_door_test(struct node *elem, struct door *door) {
    if ((*add_door(elem, door)).door->id == door->id)
        return (1);
    return (0);
}

int remove_door_test(struct node *elem, struct node *root) {
    if (find_door(elem->door->id, root) != NULL) {
        remove_door(find_door(elem->door->id, root), root);
        if (find_door(elem->door->id, root) == NULL)
            return (1);
    }
    return (0);
}
