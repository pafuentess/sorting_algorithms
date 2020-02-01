#include "sort.h"
#include <stdio.h>


void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1, *cpy_tmp1, *reverse, *cpy_list;

	tmp1 = (*list)->next;

	while (tmp1->next != NULL)
	{
		if (tmp1->n > tmp1->prev->n)
			tmp1 = tmp1->next;
		else
		{
			cpy_tmp1 = tmp1;
			reverse = tmp1;
			tmp1 = tmp1->next;
			tmp1->prev = cpy_tmp1->prev;
			cpy_tmp1->prev->next = tmp1;
			reverse = cpy_tmp1->prev;
			while (reverse->prev != NULL)
			{
				if (cpy_tmp1->n < reverse->n && reverse->prev != NULL && cpy_tmp1->n > reverse->prev->n)
				{
					reverse->prev->next = cpy_tmp1;
					reverse->prev = cpy_tmp1;
					cpy_tmp1->prev = reverse->prev;
					cpy_tmp1->next = reverse;
					cpy_list = *list;
					printf("tmp1 = %d, cpy = %d, rev = %d\n", tmp1->n, cpy_tmp1->n, reverse->n);
					print_list(cpy_list);
					printf("hola paula");
				}
				reverse = reverse->prev;
			}
			printf("tmp1 = %d, cpy = %d, rev = %d", tmp1->n, cpy_tmp1->n, reverse->n);
		}
	}
}
