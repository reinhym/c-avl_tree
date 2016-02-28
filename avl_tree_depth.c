#include "avl_tree_depth.h"

struct depth get_depth(struct node *node, int current_depth, int deepest_depth)
{
	struct depth node_depth;
	struct depth left_depth;
	struct depth right_depth;
	
	if (!node)
	{
		node_depth.current_depth = current_depth;
		node_depth.deepest_depth = deepest_depth;
		return node_depth;
	}
	
	current_depth++;
	deepest_depth = current_depth > deepest_depth ? current_depth : deepest_depth;
	
	if (node->left)
	{
		left_depth = get_depth(node->left, current_depth, deepest_depth);
	}
	
	if (node->right)
	{
		right_depth = get_depth(node->right, current_depth, deepest_depth);
	}
	
	if (node->left && node->right)
	{
		if (left_depth.deepest_depth > right_depth.deepest_depth)
		{
			node_depth.deepest_depth = left_depth.deepest_depth;
		}
		else
		{
			node_depth.deepest_depth = right_depth.deepest_depth;
		}
	}
	else if (node->left)
	{
		node_depth.deepest_depth = left_depth.deepest_depth;
	}
	else if (node->right)
	{
		node_depth.deepest_depth = right_depth.deepest_depth;
	}
	else
	{
		node_depth.deepest_depth = deepest_depth;
	}
	
	node_depth.current_depth = --current_depth;
	
	return node_depth;
}