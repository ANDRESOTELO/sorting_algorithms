#include "sort.h"

/**
 * insertion_sort_list - Insertion sort algorithm
 * @list: Entry data structure doubly linked list
 * Return: Don´t return anything
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *anterior;

	if (!list || !list->next)
		return;

	while (current)
	{
		anterior = current->prev;

		while (anterior)
		{
			if (anterior->n > current->n)
			{
				if (anterior->prev)
					anterior->prev->next = current;

				if (current->next)
					current->next->prev = anterior;

				anterior->next = current->next;
				current->prev = anterior->prev;
				anterior->prev = current;
				current->next = anterior;

				if (!current->prev)
					*list = current, current = *list;

				print_list(*list);
			}
			anterior = anterior->prev;
		}
		current = current->next;
	}
}
