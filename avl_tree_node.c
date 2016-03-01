#include "avl_tree_node.h"

void init_node(struct node *target, int target_value)
{
	target->value = target_value;
	target->left = NULL;
	target->right = NULL;
}

void free_tree(struct node **head_ptr)
{
	free_node(*head_ptr);
	free(*head_ptr);
	*head_ptr = NULL;
}

void free_node(struct node *node)
{
	if (!node)
	{
		return;
	}
	
	if (node->left)
	{
		free_node(node->left);
		free(node->left);
	}
	
	if (node->right)
	{
		free_node(node->right);
		free(node->right);
	}
}