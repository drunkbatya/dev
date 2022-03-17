// Copyright [2022] <griselle>

#include "list.h"
#include "door_struct.h"
#include <stdlib.h>

struct node *init(struct door *door) {
    struct node *ret;

    ret = (struct node *)malloc(sizeof(struct node));
    ret->next = NULL;
    ret->door = door;
    return (ret);
}

struct node *add_door(struct node *elem, struct door *door) {
    struct node *ret;

    ret = (struct node *)malloc(sizeof(struct node));
    ret->next = elem->next;
    ret->door = door;
    elem->next = ret;
    return (ret);
}

struct node *find_door(int door_id, struct node *root) {
    struct node *ret;

    ret = root;
    while (ret) {
        if (ret->door->id == door_id)
            return (ret);
        ret = ret->next;
    }
    return (NULL);
}

struct node *remove_door(const struct node *elem, struct node *root) {
    struct node *ret;
    struct node *temp;

    ret = root;
    if (elem == NULL)
        return (NULL);
    while (ret) {
        if (ret->next == elem) {
            temp = ret->next->next;
            free(ret->next);
            ret->next = temp;
            ret = ret->next;
            return (ret);
        }
    }
    return (NULL);
}

void destroy(struct node *root) {
    struct node *ret;
    struct node *temp;

    ret = root;
    while (ret) {
        if (ret->next == NULL)
            return (free(ret));
        temp = ret->next;
        free(ret);
        ret = temp;
    }
}
