#ifndef AVL_TREE_CLI_H
#define AVL_TREE_CLI_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#include "avl_tree_printing.h"
#include "avl_tree_insertion.h"
#include "avl_tree_deletion.h"

void print_menu(void);
void print_invalid(void);
void clear_buffer(void);
bool valid_integer(char *input_string, int *option);
bool valid_menu_choice(char *input, int *option);
bool valid_tree_value(char *input, int *option);
int main(void);

#endif