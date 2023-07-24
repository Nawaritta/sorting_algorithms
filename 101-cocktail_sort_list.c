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
	listint_t *left = *list, *right = *list, *traversed = *list;
	int sorted = 0;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	while (right->next)
		right = right->next;

	while (!sorted)
	{
		while (traversed != right)
		{
			if (traversed->n > traversed->next->n)
			{
				swapNodes(list, traversed, traversed->next);
				if (traversed->prev == right)
					right = traversed;

			} else
				traversed = traversed->next;
		}
		while (traversed != left)
		{
			if (traversed->n < traversed->prev->n)
			{
				swapNodes(list, traversed->prev, traversed);
				if (traversed->next == left)
					left = traversed;

			} else
				traversed = traversed->prev;
		}
		left = left->next;
		right = right->prev;
		if (left == right || right->next == left)
			break;
	}

}
