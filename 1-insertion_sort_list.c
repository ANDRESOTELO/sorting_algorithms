#include "sort.h"

/**
 * insertion_sort_list - Insertion sort algorithm
 * @list: Entry data structure doubly linked list
 * Return: Don´t return anything
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *anterior;

	if (!list || !*list || !(*list)->next)
		return;

	current = *list;

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

				current->prev = anterior->prev;
				anterior->next = current->next;
				anterior->prev = current;
				current->next = anterior;

				if (!current->prev)
					*list = current;

				print_list(*list);
			}
			anterior = anterior->prev;
		}
		current = current->next;
	}
}
