#include <stdio.h>
#include <stdlib.h>
#include "libtree.h"

// Create a new btree
btree *btree_new(){
  btree *ret;
  ret = (btree*) malloc(sizeof(btree));
  ret->root = NULL;
  printf("Initialized empty tree at %d\n", ret);
  return ret;
}

// Set the rot of a btree
void btree_set_root(btree *tree, btree_node *root){
  tree->root = root;
}

// Get the root of a btree
btree_node *btree_get_root(btree *tree){
  return tree->root;
}

// Add the node pointed to by *node to the tree pointed to by *tree
void btree_push_tree(btree *tree, btree_node *node){
  btree_push(tree->root, node);
}
