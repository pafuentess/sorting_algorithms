#include "sort.h"



void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1, *tmp2;
	int number;

	tmp1 = *list;
	tmp2 = tmp1->next;

	while(tmp2->next)
	{
		if (tmp1->n < tmp2->n)
		{
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		else
		{
			number = tmp1->n;
			tmp1->n = tmp2->n;
			tmp2->n = number;
			tmp1 = *list;
			tmp2 = tmp1->next;
			print_list(*list);
		}
	
	}
}
