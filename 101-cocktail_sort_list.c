#include "sort.h"

/**
 * swap_node - function that swap the nodes
 * @list: head of doubly linked list
 * @node: node to swap
 * Return: nothing
 */

void swap_node(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}

/**
 * cocktail_sort_list - function that sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: head of doubly linked list
 * Return: nothing
 */

void cocktail_sort_list(listint_t **list)
{
	size_t flag = 1;
	listint_t *tmp;

	if (list == NULL || *list == NULL)
		return;
	tmp = *list;
	while (flag != 0)
	{
		flag = 0;
		while (tmp->next != NULL)
		{
			if (tmp->next->n < tmp->n)
			{
				swap_node(list, tmp);
				flag = 1;
				print_list(*list);
			}
			else
				tmp = tmp->next;
		}
		if (flag == 0)
			break;
		flag = 0;
		while (tmp->prev != NULL)
		{
			if (tmp->prev->n > tmp->n)
			{
				swap_node(list, tmp->prev);
				flag = 1;
				print_list(*list);
			}
			else
				tmp = tmp->prev;
		}
	}
}
