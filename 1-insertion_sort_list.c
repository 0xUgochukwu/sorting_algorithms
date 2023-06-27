#include "sort.h"


/**
 * swap - swap two nodes in a doubly linked list
 * @a: first node
 * @b: secod node
 */

void swap(listint_t *a, listint_t *b)
{
	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;
}


/**
 * insertion_sort_list - sorting a list
 * @list: double pointer to the head of the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !*list || !(*list)->next)
		return;

	current = (*list)->next;

	while (current)
	{
		temp = current;

		while (temp && temp->prev)
		{
			if (temp->prev->n > temp->n)
			{
				swap(temp->prev, temp);

				if (!temp->prev)
					*list = temp;

				print_list((const listint_t*) *list);
			}
			else
				temp = temp->prev;
		}

		current = current->next;
	}
}
