#include "sort.h"

void swapNodes(listint_t**list, listint_t *a, listint_t *b)
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
}

/**
 *  cocktail_sort_list - sorts elements of a doubly linked list
 *                       in ascending order using cocktail sort scheme
                         (a variation of the bubble sort algorithm)
 * @list: a double pointer to the doubly linked list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *left = *list, *right = NULL;
	size_t len = 0, traversed = 0;

	if (!list || !(*list) || (*list)->next == NULL)
		return;

	while (traversed < len || len == 0)
	{
		while (left->next)
		{
			if (!traversed)
				len++;

			if (left->n > left->next->n)
			{
				swapNodes(list, left,left->next);
				print_list(*list);

			} else
				left = left->next;
		}
		traversed += 1;
		right = left;
		while (right->prev)
		{
			if (right->n < right->prev->n)
			{
				swapNodes(list, right->prev, right);
				print_list(*list);

			} else
				right = right->prev;
		}
		left = right;
	}

}
