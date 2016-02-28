#include "avl_tree_balancing.h"

void rotation_L(struct node **root_ptr)
{
	struct node *root = *root_ptr;
	struct node *former_right = root->right;
	
	if (former_right->left)
	{
		root->right = root->right->left;
	}
	else
	{
		root->right = NULL;
	}
	former_right->left = root;
	*root_ptr = former_right;
}


void rotation_R(struct node **root_ptr)
{
	struct node *root = *root_ptr;
	struct node *former_left = root->left;
	
	if (former_left->right)
	{
		root->left = former_left->right;
	}
	else
	{
		root->left = NULL;
	}
	former_left->right = root;
	*root_ptr = former_left;
}

void rotation_LR(struct node **root_ptr)
{
	rotation_R(&((*root_ptr)->right));
	rotation_L(root_ptr);
}

void rotation_RL(struct node **root_ptr)
{
	rotation_L(&((*root_ptr)->left));
	rotation_R(root_ptr);
}

struct node_height balance(struct node **root_ptr)
{
	struct node_height root_height;
	struct node_height left_node_height;
	struct node_height right_node_height;
	int left_height;
	int right_height;
	
	start:
	
	if (*root_ptr == NULL)
	{
		return root_height;
	}
	
	if ((*root_ptr)->left != NULL)
	{
		left_node_height = balance(&(*root_ptr)->left);
		if (left_node_height.left > left_node_height.right)
		{
			left_height = left_node_height.left+1;
		}
		else
		{
			left_height = left_node_height.right+1;
		}
	}
	else
	{
		left_height = 0;
	}
	
	if ((*root_ptr)->right != NULL)
	{
		right_node_height = balance(&(*root_ptr)->right);
		if (right_node_height.left > right_node_height.right)
		{
			right_height = right_node_height.left+1;
		}
		else
		{
			right_height = right_node_height.right+1;
		}
	}
	else
	{
		right_height = 0;
	}
	
	if (abs(left_height-right_height) > 1)
	{
		if (left_height > right_height)
		{
			if (left_node_height.left < left_node_height.right)
			{
				rotation_RL(root_ptr);
			}
			else
			{
				rotation_R(root_ptr);
			}
		}
		else if (right_height > left_height)
		{
			if (right_node_height.right < right_node_height.left)
			{
				rotation_LR(root_ptr);
			}
			else
			{
				rotation_L(root_ptr);
			}
		}
		goto start;
	}
	
	root_height.left = left_height;
	root_height.right = right_height;
	return root_height;

}