#ifndef AVL_TREE_NODE_H
#define AVL_TREE_NODE_H

#include <stdlib.h>

struct node;
struct node
{
	int value;
	struct node *left;
	struct node *right;
};

struct node_height
{
	int left;
	int right;
};

void init_node(struct node *target, int target_value);

#endif