#include <stdio.h>
#include <stdlib.h>
#include "libtree.h"
#define DEBUG

// Test libtree stuff
int main(int argc, const char *argv[]){
  printf(">>>> Starting libtree tests\n");
  btree *tree;
  btree_node *root;
  
  tree = btree_new();
  root = btree_node_newnum(5);
  
  btree_set_root(tree, root);
}


