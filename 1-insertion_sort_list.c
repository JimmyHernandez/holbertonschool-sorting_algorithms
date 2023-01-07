#include "sort.h"
/**
 * len_list - Returns list's lenght.
 * @list: list pointer
 * Return: list lenght (len_list).
 **/
int len_list(listint_t *list)
{
	int len = 0;

	while (list != NULL)
	{
		len++;
		list = list->next;
	}
	return (len);
}

/**
 * insertion_sort_list - sort linked list.
 *@list: list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = NULL, *first = NULL, *second = NULL;
	listint_t *third = NULL, *four = NULL;

	if (!list || !(*list) || len_list(*list) < 2)
		return;
	current = *list;

	while (current != NULL)
	{
		if (current->prev && current->n < current->prev->n)
		{
			first = current->prev->prev;
			second = current->prev;
			third = current;
			four = current->next;
			/* Setting the next node of the second node to the fourth node. */
			second->next = four;
			if (four != NULL)
				four->prev = second;
			/* Creating a doubly linked list with three nodes. */
			third->next = second;
			third->prev = first;
			/*
			*Checking if the first node is NULL. If it is not NULL,
			*it sets the next node of the first node to the third node.
			*/
			if (first != NULL)
				first->next = third;
			else
				*list = third;
			/* Setting the previous node of the second node to the third node. */
			second->prev = third;
			current = *list;
			print_list(*list);
			continue;
		}
		else
			/* Moving the current node to the next node. */
			current = current->next;
	}
}
