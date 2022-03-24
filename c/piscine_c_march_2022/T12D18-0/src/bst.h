// Copyright [2022 <griselle>
#ifndef SRC_BST_H_
#define SRC_BST_H_

typedef struct s_btree {
    struct s_btree *left;
    struct s_btree *right;
    int item;
} t_btree;

t_btree *bstree_create_node(int item);
int comparator(int num, int item);
void bstree_insert(t_btree *root, int item, int (*cmpf)(int, int));
void print_num(int num);
void bstree_apply_infix(t_btree *root, void (*applyf)(int));
void bstree_apply_prefix(t_btree *root, void (*applyf)(int));
void bstree_apply_postfix(t_btree *root, void (*applyf)(int));
#endif  // SRC_BST_H_
