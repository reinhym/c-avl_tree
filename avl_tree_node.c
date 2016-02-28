#include "avl_tree_node.h"

void init_node(struct node *target, int target_value)
{
	target->value = target_value;
	target->left = NULL;
	target->right = NULL;
}