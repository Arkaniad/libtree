#include <stdio.h>
#include <stdlib.h>
#include "libtree.h"
#define DEBUG

// Test libtree stuff
int main(int argc, const char *argv[]){
  btree *tree = btree_new();
  btree_node *root = btree_node_newnum(5);
  btree_set_root(tree, root);
}


