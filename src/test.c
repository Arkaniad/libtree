#include <stdio.h>
#include <stdlib.h>
#include "libtree.h"
#define DEBUG

// Test libtree stuff
int main(int argc, const char *argv[]){
  int tests = 1;
  int success = 0;
  printf(">>>> Starting libtree tests\n");
  if(test_tree()){
    success++;
    printf(">>> [%d/%d] test_tree() SUCCESS\n", success, tests);
  } else {
    printf(">>> [%d/%d] test_tree() FAIL\n", success, tests);
  }
}

int test_tree(){
  btree *tree;
  btree_node *root;
  
  tree = btree_new();
  root = btree_node_newnum(5);
  
  btree_set_root(tree, root);
  
  if(tree->root->num == 5){
    return 1;
  } else {
    return 0;
  }
}
