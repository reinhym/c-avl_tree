#include "avl_tree_printing.h"

void fill_blanks(struct node *node, int current_depth, int deepest_depth)
{
	if (!node)
	{
		return;
	}
	
	current_depth++;
	
	if (deepest_depth > current_depth)
	{
		if (node->left)
		{
			fill_blanks(node->left, current_depth, deepest_depth);
		}
		else
		{
			node->left = malloc(sizeof(struct node));
			init_node(node->left, -1);
			fill_blanks(node->left, current_depth, deepest_depth);
		}
		
		if (node->right)
		{
			fill_blanks(node->right, current_depth, deepest_depth);
		}
		else
		{
			node->right = malloc(sizeof(struct node));
			init_node(node->right, -1);
			fill_blanks(node->right, current_depth, deepest_depth);
		}
	}
}

void clear_blanks(struct node *node)
{
	if (!node)
	{
		return;
	}
	
	if (node->left)
	{
		clear_blanks(node->left);
		if (node->left->value == -1)
		{
			free(node->left);
			node->left = NULL;
		}
	}
	
	if (node->right)
	{
		clear_blanks(node->right);
		if (node->right->value == -1)
		{
			free(node->right);
			node->right = NULL;
		}
	}
}

void write_node(struct node_print_line *printout, struct node *node, 
	int current_depth, int deepest_depth)
{
	int i;
	int j;
	
	if (!node)
	{
		return;
	}
	
	current_depth++;
	
	if (node->left)
	{
		write_node(printout, node->left, current_depth, deepest_depth);
	}
	
	if (printout[current_depth-1].size < 81)
	{
		if (node->value > 0)
		{
			sprintf(&printout[current_depth-1].line[printout[current_depth-1].size],
				"%1d", node->value);
		}
		else
		{
			printout[current_depth-1].line[printout[current_depth-1].size] = '-';
		}
		printout[current_depth-1].size++;
	}
	
	j = pow(2,deepest_depth-current_depth+1)-1;
	for (i = 0; i < j && printout[current_depth-1].size < 81; i++)
	{
		printout[current_depth-1].line[printout[current_depth-1].size] = ' ';
		printout[current_depth-1].size++;
	}
	
	if (node->right)
	{
		write_node(printout, node->right, current_depth, deepest_depth);
	}
}

void print_node(struct node *root)
{
	int i;
	int j;
	struct depth depth;
	struct node_print_line *printout;
	
	depth = get_depth(root, 0, 0);
	fill_blanks(root, 0, depth.deepest_depth);
	
	printout = malloc(sizeof(struct node_print_line)*depth.deepest_depth);
	for (i = 0; i < depth.deepest_depth; i++)
	{
		for (j = 0; j <= 81; j++)
		{
			printout[i].line[j] = '\0';
		}
		printout[i].size = 0;
	}
	
	for (i = 0; i < depth.deepest_depth; i++)
	{
		int j;
		int k = pow(2,depth.deepest_depth-i-1)-1;
		for (j = 0; j < k && printout[i].size < 81; j++)
		{
			printout[i].line[printout[i].size] = ' ';
			printout[i].size++;
		}
	}
	
	write_node(printout, root, 0, depth.deepest_depth);
	
	printf("=========================\n");
	
	for (i = 0; i < depth.deepest_depth; i++)
	{
		printf("%s\n", printout[i].line);
	}
	
	printf("=========================\n\n");
	
	free(printout);
	
	clear_blanks(root);
}