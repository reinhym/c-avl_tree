#ifndef AVL_TREE_PRINTING_H
#define AVL_TREE_PRINTING_H

#include <stdio.h>
#include <math.h>

#include "avl_tree_node.h"
#include "avl_tree_depth.h"

struct node_print_line
{
	char line[81];
	int size;
};

void fill_blanks(struct node *node, int current_depth, int deepest_depth);
void clear_blanks(struct node *node);
void write_node(struct node_print_line *printout, struct node *node, 
int current_depth, int deepest_depth);
void print_node(struct node *root);

#endif