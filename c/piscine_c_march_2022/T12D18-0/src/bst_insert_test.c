// Copyright [2022 <griselle>

#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int insert_test(t_btree *left_ptr, t_btree *right_ptr) {
    if (left_ptr->left->item != 1)
        return (0);
    if (left_ptr->right->item != 3)
        return (0);
    if (right_ptr->right->item != 10)
        return (0);
    return (1);
}

void print_before_insert(t_btree *root_ptr, t_btree *left_ptr, t_btree *right_ptr) {
    printf("    %d\n", root_ptr->item);
    printf("   / \\\n");
    printf("  /   \\\n");
    printf(" %d     %d\n", left_ptr->item, right_ptr->item);
    printf("/ \\   / \\\n");
}

void printf_second_insert(t_btree *root_ptr, t_btree *left_ptr, t_btree *right_ptr) {
    printf("       %d\n", root_ptr->item);
    printf("      / \\\n");
    printf("     /   \\\n");
    printf("    %d     %d\n", left_ptr->item, right_ptr->item);
    printf("   / \\   / \\\n");
    printf("  /   \\     \\\n");
    printf(" %d     %d     %d\n", left_ptr->left->item, left_ptr->right->item, right_ptr->right->item);
    printf("/ \\   / \\   / \\\n");
}


int main(void) {
    t_btree *root_ptr;
    t_btree *left_ptr;
    t_btree *right_ptr;

    root_ptr = bstree_create_node(4);
    left_ptr = bstree_create_node(2);
    right_ptr = bstree_create_node(6);

    root_ptr->left = left_ptr;
    root_ptr->right = right_ptr;

    printf("Tree before insert:\n");
    print_before_insert(root_ptr, left_ptr, right_ptr);

    bstree_insert(root_ptr, 3, comparator);
    bstree_insert(root_ptr, 1, comparator);
    bstree_insert(root_ptr, 10, comparator);

    printf("\nTree after inserting 3, 1, 10\n");
    printf_second_insert(root_ptr, left_ptr, right_ptr);

    printf("\nTesting..");
    if (insert_test(left_ptr, right_ptr))
        printf("Success!\n");
    else
        printf("Fail\n");
    free(left_ptr->left);
    free(left_ptr->right);
    free(right_ptr->right);
    free(root_ptr);
    free(left_ptr);
    free(right_ptr);
    return (0);
}
