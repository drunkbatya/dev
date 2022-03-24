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
    printf("Printing tree:\n");
    printf("   %d\n", root_ptr->item);
    printf("  / \\\n");
    printf(" %d   %d\n", left_ptr->item, right_ptr->item);
    printf("/     \\\n\n");
    printf("Testing..");
    if ((left_ptr->item < root_ptr->item) && (root_ptr->item < right_ptr->item))
        printf("Success!\n");
    else
        printf("Fail\n");
    free(root_ptr);
    free(left_ptr);
    free(right_ptr);
    return (0);
}
