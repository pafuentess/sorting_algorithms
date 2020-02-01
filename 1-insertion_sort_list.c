#include "sort.h"
#include <stdio.h>


void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1, *next;

	tmp1 = (*list)->next;

	while (tmp1)
	{
		next = tmp1->next;
		if (tmp1->prev != NULL && tmp1->prev->n > tmp1->n)
		{
			tmp1->prev->next = tmp1->next;
			if (tmp1->next != NULL)
				tmp1->next->prev = tmp1->prev;
			while (tmp1->prev != NULL && tmp1->prev->n > tmp1->n)
			{
				tmp1->next = tmp1->prev;
				tmp1->prev = tmp1->prev->prev;
			}
			if (tmp1->prev == NULL)
				*list = tmp1;
			else
				tmp1->prev->next = tmp1;
			tmp1->next->prev = tmp1;
			print_list(*list);
		}
		tmp1= next;
	}
}
