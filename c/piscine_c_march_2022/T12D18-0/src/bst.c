// Copyright [2022 <griselle>

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

t_btree *bstree_create_node(int item) {
    t_btree *ptr;

    ptr = malloc(sizeof(t_btree));
    ptr->item = item;
    ptr->left = NULL;
    ptr->right = NULL;
    return (ptr);
}

int comparator(int num, int item) {
    if (item < num)
        return (-1);
    if (item > num)
        return (1);
    return (0);
}

void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int)) {
    t_btree *ptr;

    ptr = root;
    while (1) {
        int comp_value;

        comp_value = cmpf(ptr->item, item);
        if (comp_value == -1) {
            if (ptr->left == NULL) {
                ptr->left = bstree_create_node(item);
                return;
            }
            ptr = ptr->left;
        }
        if (comp_value == 1) {
            if (ptr->right == NULL) {
                ptr->right = bstree_create_node(item);
                return;
            }
            ptr = ptr->right;
        }
        if (comp_value == 0) {
            printf("Insert error! Value %d already exist in tree!\n", item);
            return;
        }
    }
}

void print_num(int num) {
    printf("%d ", num);
}

void bstree_apply_infix(t_btree *root, void (*applyf)(int)) {
    if (root == NULL)
        return;
    bstree_apply_infix(root->left, applyf);
    applyf(root->item);
    bstree_apply_infix(root->right, applyf);
}
void bstree_apply_prefix(t_btree *root, void (*applyf)(int)) {
    if (root == NULL)
        return;
    applyf(root->item);
    bstree_apply_infix(root->left, applyf);
    bstree_apply_infix(root->right, applyf);
}

void bstree_apply_postfix(t_btree *root, void (*applyf)(int)) {
    if (root == NULL)
        return;
    bstree_apply_infix(root->right, applyf);
    applyf(root->item);
    bstree_apply_infix(root->left, applyf);
}

