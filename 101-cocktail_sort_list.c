#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 *
 * @list: double pointer to the head of the list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *prev_node1, *next_node1, *next_node2;

	if (node1 == NULL || node2 == NULL)
		return;

	prev_node1 = node1->prev;
	next_node1 = node1->next;
	next_node2 = node2->next;

	if (prev_node1 != NULL)
		prev_node1->next = node2;
	else
		*list = node2;

	if (next_node2 != NULL)
		next_node2->prev = node1;

	node2->prev = prev_node1;
	node2->next = node1;
	node1->prev = node2;
	node1->next = next_node2;

	if (next_node1 != NULL)
		next_node1->prev = node2;
}


/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 *                      order using the Cocktail shaker sort algorithm
 *
 * @list: double pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 0;
	listint_t *curr;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	do {
		swapped = 0;
		for (curr = *list; curr->next != NULL; curr = curr->next)
		{
			if (curr->n > curr->next->n)
			{
				swap_nodes(list, curr, curr->next);
				print_list(*list);
				swapped = 1;
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		for (curr = curr->prev; curr->prev != NULL; curr = curr->prev)
		{
			if (curr->n < curr->prev->n)
			{
				swap_nodes(list, curr->prev, curr);
				print_list(*list);
				swapped = 1;
			}
		}
	} while (swapped);
}

