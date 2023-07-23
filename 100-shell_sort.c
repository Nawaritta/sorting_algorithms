#include "sort.h"
/**
 * insertion_sort_list - sorts a doubly linked list in ascending order
                         using the insert sorting algorithm.
 * @list: The doubly linked list to sort.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *cursor, *tmp;
	int insert = 0;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;

	while (current != NULL)
	{
		tmp = current;
		if (current->prev != NULL)
			cursor = current->prev;

		while (cursor)
		{
			if (cursor->n > current->n)
			{
				insert = 1;
				cursor->next = current->next;
				if (current->next != NULL)
					current->next->prev = cursor;

			}
			if (insert)
			{
				current->next = cursor;
				current->prev = cursor->prev;
				if (cursor->prev != NULL)
					cursor->prev->next = current;

				cursor->prev = current;
				insert = 0;

				if ((*list)->prev != NULL)
					(*list) = (*list)->prev;
				print_list(*list);
			}
			cursor = cursor->prev;
		}

			current = tmp->next;
	}

}
