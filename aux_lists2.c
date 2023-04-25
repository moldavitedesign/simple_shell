#include "main.h"

/**
 * add_rvar_node - Adds a variable at the end of a r_var list.
 * @head: Pointer to the head of the linked list.
 * @lvar: Length of the variable.
 * @val: Value of the variable.
 * @lval: Length of the value.
 *
 * Return: Pointer to the head.
 */
r_var *add_rvar_node(r_var **head, int lvar, char *val, int lval)
{
	r_var *new_node, *temp;

	new_node = malloc(sizeof(r_var));
	if (new_node == NULL)
		return (NULL);

	new_node->len_var = lvar;
	new_node->val = val;
	new_node->len_val = lval;

	new_node->next = NULL;
	temp = *head;

	if (temp == NULL)
	{
		*head = new_node;
		}
	else
	{
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new_node;
	}

	return (*head);
}

/**
 * free_rvar_list - Frees a r_var list.
 * @head: Pointer to the head of the linked list.
 *
 * Return: void.
 */
void free_rvar_list(r_var **head)
{
	r_var *temp, *curr;

	if (head != NULL)
	{
		curr = *head;
		while ((temp = curr) != NULL)
		{
			curr = curr->next;
			free(temp->val);
			free(temp);
		}
		*head = NULL;
	}
}

