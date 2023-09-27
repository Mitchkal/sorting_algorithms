#include "sort.h"
/**
 * insertion_sort_list - sorts list by insertion
 * @list: the linked list
 */
void insertion_sort_list(listint_t **list)
{
		listint_t *current = NULL, *prev_node = NULL, *next_node = NULL;

		if (list == NULL || *list == NULL || (*list)->next == NULL)
			return;
		current = (*list)->next;
		next_node = current->next;
		while (current != NULL)
		{
			if (current->n < current->prev->n)
			{
				prev_node = current->prev;
				while (prev_node != NULL && (current->n < prev_node->n))
				{
					if (prev_node->prev == NULL)
					{
						prev_node->prev = current;
						current->prev->next = current->next;
						if (current->next != NULL)
							current->next->prev = current->prev;
						current->next = prev_node;
						current->prev = NULL;
						*list = current;
					}
					else
					{
						current->prev->next = current->next;
						if (current->next != NULL)
							current->next->prev = current->prev;
						prev_node->prev->next = current;
						current->prev = prev_node->prev;
						prev_node->prev = current;
						current->next = prev_node;
					}
					print_list(*list);
					prev_node = current->prev;
				}
			}
			current = next_node;
			current ? (next_node = current->next) : (next_node = NULL);
		}
}
