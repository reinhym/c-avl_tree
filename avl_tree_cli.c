#include "avl_tree_cli.h"

void print_menu(void)
{
	printf("AVL-TREE MENU\n=============\n\
[1] insert into tree\n\
[2] delete from tree\n\
[3] print tree\n\
[4] exit program\n\n\
Enter option: ");
}

void print_invalid(void)
{
	printf("\nERROR: invalid input\n\n");
}

void clear_buffer(void)
{
	int c;
	do
	{
		c = getchar();
	} while (c != '\n' && c != EOF);
}

bool valid_integer(char *input_string, int *option)
{
	char *end_ptr;
	int parsed_value;
	
	if (input_string[strlen(input_string)-1] != '\n')
	{
		clear_buffer();
		return false;
	}
	
	input_string[strlen(input_string)-1] = '\0';
	
	parsed_value = strtol(input_string, &end_ptr, 10);
	
	if (*end_ptr != '\0')
	{
		return false;
	}
	
	*option = parsed_value;
	
	return true;
}

bool valid_menu_choice(char *input, int *option)
{
	if (!valid_integer(input,option) || *option < 1 || *option > 4)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool valid_tree_value(char *input, int *option)
{
	if (!valid_integer(input,option))
	{
		return false;
	}
	
	if (*option > 0 && *option < 10)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main(void)
{
	struct node *head = NULL;
	
	char input_string[4];
	int option = 0;
	
	for(;;)
	{
		print_menu();
		
		fgets(input_string, 3, stdin);
		if (!valid_menu_choice(input_string, &option))
		{
			print_invalid();
			continue;
		}
		
		while (option == 1)
		{
			int value;
			printf("add (1-9) or ENTER to cancel: ");
			
			fgets(input_string, 3, stdin);
			if (input_string[0] == '\n')
			{
				printf("\n");
				break;
			}
			else if (!valid_tree_value(input_string, &value))
			{
				print_invalid();
				continue;
			}
			
			insert(&head, value);
			print_node(head);
		}
		
		if (option == 2)
		{
			print_node(head);
			while (option == 2)
			{
				int value;
				printf("delete (1-9) or ENTER to cancel: ");
				
				fgets(input_string, 3, stdin);
				if (input_string[0] == '\n')
				{
					printf("\n");
					break;
				}
				else if (!valid_tree_value(input_string, &value))
				{
					print_invalid();
					continue;
				}
				
				deletion(&head, value);
				print_node(head);
			}
		}
		
		if (option == 3)
		{
			printf("\n");
			print_node(head);
		}
		
		if (option == 4)
		{
			break;
		}
	}
	printf("program exiting\n");
	free_tree(&head);
	return EXIT_SUCCESS;
}