#include <stdio.h>
#include "libtree.h"

// Walk from the given node and print contents
void print_from_node(btree_node *current){
  btree_node *left;
  btree_node *right;
  left = (btree_node*)current->left;
  right = (btree_node*)current->right;
  printf("   At node %d (%d)\n", current->num, current);
  if(left != NULL){
    printf("<< Node %d has left child at %d\n", current->num, left);
    print_from_node(left);
  }
  if(right != NULL){
    printf(">> Node %d has right child at %d\n", current->num, right);
    print_from_node(right);
  }
}

// Print an entire btree
void print_tree(btree *tree){
  btree_node *root = tree->root;
  print_from_node(root);
}
