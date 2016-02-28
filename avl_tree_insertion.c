#include "avl_tree_insertion.h"

void insert(struct node **head_ptr, int value)
{
	struct node *current;
	
	if (*head_ptr == NULL)
	{
		*head_ptr = malloc(sizeof(struct node));
		init_node(*head_ptr, value);
		return;
	}
	
	current = *head_ptr;
	
	if (value > current->value && current->right != NULL)
	{
		insert(&(current->right), value);
	}
	else if (value <= current->value && current->left != NULL)
	{
		insert(&(current->left), value);
	}
	else if (value > current->value)
	{
		current->right = malloc(sizeof(struct node));
		init_node(current->right, value);
	}
	else if (value <= current->value)
	{
		current->left = malloc(sizeof(struct node));
		init_node(current->left, value);
	}
	
	balance(head_ptr);
}