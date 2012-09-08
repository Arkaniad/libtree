#include <stdio.h>

// Basic node structure.
typedef struct{
  int num;
  int *left;
  int *right;
} btree_node;

typedef struct{
  btree_node *root;
} btree;

void print_tree(btree_node *root);
btree_node *btree_node_new();
btree_node *btree_node_newnum(int num);
void btree_push(btree_node *node, btree_node *root);

