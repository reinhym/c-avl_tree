#ifndef AVL_TREE_DEPTH_H
#define AVL_TREE_DEPTH_H

#include "avl_tree_node.h"

struct depth
{
	int current_depth;
	int deepest_depth;
};

struct depth get_depth(struct node *node, int current_depth, int deepest_depth);

#endif