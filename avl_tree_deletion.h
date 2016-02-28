#ifndef AVL_TREE_DELETION_H
#define AVL_TREE_DELETION_H

#include <stdio.h>
#include <stdlib.h>

#include "avl_tree_node.h"
#include "avl_tree_depth.h"
#include "avl_tree_balancing.h"

enum direction { neither=1, left=2, right=3 };

void deletion(struct node **head_ptr, int value);

#endif