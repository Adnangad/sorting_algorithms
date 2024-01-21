#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insertion_sort_list - sorts a doubly linked listed thru insertion sort
 * @list:the list to be sorted
 *
 * Return:none.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *a;
	listint_t *b;
	listint_t *c, *temp;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
	{
		return;
	}
	a = (*list)->next;

	while (a)
	{
		b = a->prev;
		c = a;

		while (b && b->n > c->n)
		{
			temp = c->next;

			if (temp)
				temp->prev = b;
			c->prev = b->prev;

			if (c->prev)
				c->prev->next = c;
			else
				*list = c;
			b->prev = c;
			b->next = temp;
			c->next = b;
			print_list(*list);
			b = c->prev;
		}
		a = a->next;
	}
}
