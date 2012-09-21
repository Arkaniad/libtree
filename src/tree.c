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

// Get a specific node from a tree
btree_node *btree_get_node(btree *tree, int num){
  btree_node *root;
  root = tree->root;
  if(root->num == num){
    return root;
  } else {
    if(root->num < num){
      if(root->right != NULL) {
        return btree_get_node((btree_node *)root->right, num);
      } else {
        return (btree_node*) NULL;
      }
    } else {
      if(root->left != NULL) {
        return btree_get_node(root->left, num);
      } else {
        return (btree_node*) NULL;
      }
    }
  }
}
