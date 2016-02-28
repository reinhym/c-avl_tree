#include "avl_tree_deletion.h"

void deletion(struct node **head_ptr, int value)
{
	struct node *parent = NULL;
	enum direction path = neither;
	struct node *current = *head_ptr;
	
	struct node *parent_minimum = NULL;
	struct node *minimum = NULL;
	
	if (*head_ptr == NULL)
	{
		return;
	}
	
	while (current->value != value)
	{
		if (value > current->value && current->right)
		{
			parent = current;
			path = right;
			current = current->right;
		}
		else if (value < current->value && current->left)
		{
			parent = current;
			path = left;
			current = current->left;
		}
		else
		{
			return;
		}
	}
	
	if (current->left && current->right)
	{
		if (current->right->left)
		{
			parent_minimum = current->right;
			minimum = current->right->left;
			while (minimum->left)
			{
				parent_minimum = minimum;
				minimum = minimum->left;
			}
			if (minimum->right)
			{
				parent_minimum->left = minimum->right;
				minimum->right = NULL;
			}
			else
			{
				parent_minimum->left = NULL;
			}
			minimum->left = current->left;
			minimum->right = current->right;
		}
		else
		{
			minimum = current->right;
			minimum->left = current->left;
		}
		
		if (path == neither)
		{
			*head_ptr = minimum;
		}
		else if (path == left)
		{
			parent->left = minimum;
		}
		else if (path == right)
		{
			parent->right = minimum;
		}
	}
	else if (current->left)
	{
		if (path == neither)
		{
			*head_ptr = current->left;
		}
		else if (path == left)
		{
			parent->left = current->left;
		}
		else if (path == right)
		{
			parent->right = current->left;
		}
	}
	else if (current->right)
	{
		if (path == neither)
		{
			*head_ptr = current->right;
		}
		else if (path == left)
		{
			parent->left = current->right;
		}
		else if (path == right)
		{
			parent->right = current->right;
		}
	}
	else
	{
		if (path == neither)
		{
			*head_ptr = NULL;
		}
		else if (path == left)
		{
			parent->left = NULL;
		}
		else if (path == right)
		{
			parent->right = NULL;
		}
	}
	free(current);
	current = NULL;
	balance(&(*head_ptr));
}