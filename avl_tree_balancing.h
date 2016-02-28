#ifndef AVL_TREE_BALANCING_H
#define AVL_TREE_BALANCING_H

#include "avl_tree_node.h"

void rotation_L(struct node **root_ptr);
void rotation_R(struct node **root_ptr);
void rotation_LR(struct node **root_ptr);
void rotation_RL(struct node **root_ptr);
struct node_height balance(struct node **root_ptr);

#endif