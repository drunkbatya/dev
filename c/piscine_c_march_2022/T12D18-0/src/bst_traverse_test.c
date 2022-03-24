// Copyright [2022 <griselle>

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(void) {
    t_btree *root_ptr;
    t_btree *left_ptr;
    t_btree *right_ptr;

    root_ptr = bstree_create_node(4);
    left_ptr = bstree_create_node(2);
    right_ptr = bstree_create_node(6);

    root_ptr->left = left_ptr;
    root_ptr->right = right_ptr;

    bstree_insert(root_ptr, 3, comparator);
    bstree_insert(root_ptr, 1, comparator);
    bstree_insert(root_ptr, 10, comparator);

    printf("Infix: ");
    bstree_apply_infix(root_ptr, print_num);
    printf("\nPrefix: ");
    bstree_apply_prefix(root_ptr, print_num);
    printf("\nPostfix: ");
    bstree_apply_postfix(root_ptr, print_num);
    printf("\n");

    free(left_ptr->left);
    free(left_ptr->right);
    free(right_ptr->right);
    free(root_ptr);
    free(left_ptr);
    free(right_ptr);
    return (0);
}
