#include <stdio.h>

// Basic node structure.
typedef struct{
  int    num;
  struct btree_node *left;
  struct btree_node *right;
} btree_node;

typedef struct{
  btree_node *root;
} btree;

// Debug Functions
void print_from_node(btree_node *root);
void print_tree(btree *tree);

// Node Functions
btree_node *btree_node_new();
btree_node *btree_node_newnum(int num);
void        btree_push(btree_node *root, btree_node *node);

// Tree Functions
btree      *btree_new();
void        btree_set_root(btree *tree, btree_node *root);
btree_node *btree_get_root(btree *tree);
void        btree_push_tree(btree *tree, btree_node *node);
