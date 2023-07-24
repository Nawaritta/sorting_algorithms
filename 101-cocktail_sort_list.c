#include "sort.h"

/**
 * swapNodes - swaps two adjacent nodes in a doubly linked list
 * @list: a doubly linked list
 * @a: the node on the left
 * @b: the node on the right
 */

void swapNodes(listint_t **list, listint_t *a, listint_t *b)
{

	if (a->prev)
		a->prev->next = b;
	else
		*list = b;
	if (b->next)
		b->next->prev = a;
	b->prev = a->prev;
	a->next = b->next;
	b->next = a;
	a->prev = b;
	print_list(*list);
}

/**
 *  cocktail_sort_list - sorts elements of a doubly linked list
 *                       in ascending order using cocktail sort scheme
 *                       (a variation of the bubble sort algorithm)
 * @list: a double pointer to the doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left = *list, *right = NULL;
	size_t len = 0, traversed = 0, swaps = 1;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	while (swaps && (traversed < len + 1))
	{
		swaps = 0;
		while (left->next)
		{
			if (!traversed)
				len++;

			if (left->n > left->next->n)
			{
				swapNodes(list, left, left->next);
				swaps++;

			} else
				left = left->next;
		}
		swaps = 0;
		traversed += 1;
		right = left;
		while (right->prev)
		{
			if (right->n < right->prev->n)
			{
				swapNodes(list, right->prev, right);
				swaps++;

			} else
				right = right->prev;
		}
		left = right;
	}
}
