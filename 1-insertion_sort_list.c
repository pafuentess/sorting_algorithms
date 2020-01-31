#include "sort.h"
#include <stdio.h>


void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1, *tmp2;

	tmp1 = *list;
	tmp2 = tmp1->next;

	while (tmp2->next)
	{
		if (tmp1->n < tmp2->n)
		{
			while(tmp1->prev != NULL)
			{
				if (tmp1->n > tmp2->n)
				{
					tmp1 = tmp1->prev;
				}
				else
				{
					tmp2->next = tmp1;
					tmp2->prev = tmp1->prev;
					print_list(*list);
				}
				
			}
		}
		else
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		
	}
}
