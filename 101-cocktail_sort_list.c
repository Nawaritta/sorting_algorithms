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
	listint_t *check = *list;
	size_t range = 0, traversed;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	while (check)
	{
		check = check->next;
		range++;
	}
	check = (*list);
	while (range)
	{
		traversed = 0;

		while (check->next && traversed < range)
		{
			if (check->n > check->next->n)
				swapNodes(list, check, check->next);
			else
				check = check->next;
			traversed++;
		}
		traversed = 0;
		range--;
		while (check->prev && traversed < range)
		{
			if (check->n < check->prev->n)
				swapNodes(list, check->prev, check);
			else
				check = check->prev;
			traversed++;
		}
	}
}
