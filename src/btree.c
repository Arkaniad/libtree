#include <stdio.h>
#include <stdlib.h>
#include "btree.h"
#define DEBUG

int main(int argc, const char *argv[]){
}

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

// Create a new btree
btree *btree_new(){
  btree ret;
  ret.root = NULL;
  printf("Initialized empty tree at %d", &ret);
}

// Set the rot of a btree
void btree_set_root(btree *tree, btree_node *root){
  tree->root = root;
}

// Get the root of a btree
btree_node *btree_get_root(btree *tree){
  return tree->root;
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

// Add the node pointed to by *node to the tree pointed to by *tree
void btree_push_tree(btree *tree, btree_node *node){
  btree_push(tree->root, node);
}
