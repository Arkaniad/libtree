#include <stdio.h>
#include <stdlib.h>
#include "libtree.h"

// Create an empty btree_node
btree_node *btree_node_new(){
  btree_node *ret;
  ret = (btree_node*) malloc(sizeof(btree_node));
  ret->num   = 0;
  ret->left  = (struct btree_node*) NULL;
  ret->right = (struct btree_node*) NULL;
  printf("Initialized blank node at %d\n", ret);
  return ret;
}

// Create a new btree_node with key of num
btree_node *btree_node_newnum(int num){
  btree_node *ret;
  ret = (btree_node*) malloc(sizeof(btree_node));
  ret->num   = num;
  ret->left  = (struct btree_node*) NULL;
  ret->right = (struct btree_node*) NULL;
  printf("Initialized node at %d with num %d\n", ret, ret->num);
  return ret;
}

// Add to the given node the node given at the end
void btree_push(btree_node *root, btree_node *node) {
  printf("Adding node %d to tree with root at node %d\n", node->num, root->num);
  if(node->num < root->num) {
    printf("Node %d will go on the left of node %d\n", node->num, root->num);
    if(root->left != NULL){
      printf("Node %d will traverse down left.\n", node->num);
      btree_push((btree_node*)root->left, node);
    } else {
      printf("Adding node %d to left of node %d\n", node->num, root->num);
      root->left = (struct btree_node*) node;
    }
  } else if(node->num > root->num) {
    printf("Node %d will go on the right of node %d\n", node->num, root->num);
    if(root->right != NULL){
      printf("Node %d will traverse down right.\n", node->num);
      btree_push((btree_node*)root->right, node); 
  } else {
      printf("Adding node %d to right of node %d\n", node->num, root->num);
      root->right = (struct btree_node*) node;
    }
  } else {
    printf("Leaf was not added, duplicate entry.\n");
  }
  
}
