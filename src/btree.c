#include <stdio.h>
#include "btree.h"
#define DEBUG

int main(int argc, const char *argv[]){
  btree_node root = *btree_node_newnum(5);
  btree_node left = *btree_node_newnum(4);
  btree_node left_left = *btree_node_newnum(3);
  btree_node right = *btree_node_newnum(7);
  btree_node right_right = *btree_node_newnum(8);
  btree_node right_left = *btree_node_newnum(6);
  btree_push(&root, &left); 
  btree_push(&root, &left_left);
  btree_push(&root, &right);
  btree_push(&root, &right_right);
  btree_push(&root, &right_left);
  print_tree(&root);
}

void print_tree(btree_node *current){
  printf("Printing tree starting at root (node %d)\n", (*current).num);
  printf("Node's leaves: (%d(%d) < > %d(%d))\n", (*current).left, *((*current).left).num, (*current).right, *((*current).right).num);
  if((*current).left != NULL){
    printf("Descending left and printing.\n");
    print_tree((*current).left);
  }
  if((*current).right != NULL){
    printf("Descending right and printing.\n");
    print_tree((*current).right);
  }
}

btree_node *btree_node_new(){
  btree_node ret;
  ret.num = NULL;
  ret.left = NULL;
  ret.right = NULL;
  printf("Initialized blank node at %d\n", &ret);
  return &ret;
}

btree_node *btree_node_newnum(int num){
  btree_node ret;
  ret.num = num;
  ret.left = NULL;
  ret.right = NULL;
  printf("Initialized node at %d with num %d\n", &ret, ret.num);
  return &ret;
}

void btree_push(btree_node *top, btree_node *add) {
  printf("Adding node %d to tree with root at node %d\n", (*add).num, (*top).num);
  if((*add).num < (*top).num) {
    printf("Node %d will go on the left of node %d\n", (*add).num, (*top).num);
    if((*top).left != NULL){
      printf("Node %d will traverse down left.\n", (*add).num);
      btree_push((*top).left, add);
    } else {
      printf("Adding node %d to left of node %d\n", (*add).num, (*top).num);
      (*top).left = add;
    }
  } else if((*add).num > (*top).num) {
    printf("Node %d will go on the right of node %d\n", (*add).num, (*top).num);
    if((*top).right != NULL){
      printf("Node %d will traverse down right.\n", (*add).num);
      btree_push((*top).right, add); 
  } else {
      printf("Adding node %d to right of node %d\n", (*add).num, (*top).num);
      (*top).right = add;
    }
  } else {
    printf("Leaf was not added, duplicate entry.\n");
  }
  
}
