#include "sort.h"
#include <stdio.h>


void insertion_sort_list(listint_t **list)
{
	listint_t *tmp1, *tmp2, *reverse, *cpy;

	tmp1 = *list;
	tmp2 = tmp1->next;

	while (tmp2->next)
	{
		printf("tmp1 = %d, tmp2 = %d\n", tmp1->n, tmp2->n);
		if (tmp1->n < tmp2->n)
                        printf("true\n");
		else
		{
			reverse = tmp1->prev;
			printf("reverse %d\n", reverse->n);
			printf("false\n");
			while (reverse->n < tmp2->n && reverse->prev != NULL)
			{
				printf("entro al while\n");
				if (reverse->prev != NULL)
					reverse = reverse->prev;
				printf("reverse %d\n", reverse->n);
			}
			cpy = tmp2;
			tmp2->next = tmp1;
			tmp2->prev = reverse;
			reverse->next = tmp2;
			tmp1->prev = tmp2;
			tmp1->next = cpy->next;
			cpy->next = tmp1;
			print_list(*list);
		}
		tmp1 = tmp1->next;
		tmp2 = tmp2->next;
	}
}

/*
if (tmp2->n < reverse->n && tmp2->n > reverse->prev->n)
                                        printf("%d entre estos dos cabe el nodo\n", i);
                                else
                                {
                                        printf("tengo que mover reverse\n");
                                        if (reverse->prev != NULL)
                                                reverse = reverse->prev;
                                        printf("valor reverse %d\n", reverse->n);
                                        break;
                                }
*/
