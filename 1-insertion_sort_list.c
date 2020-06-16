#include "sort.h"
/**
 *decalage - decalage liste
 *@node: node
 */
void decalage(listint_t *node)
{
	node->next = node->prev;
	node->prev = node->prev->prev;
	node->next->prev = node;
}
/**
 * insertion_sort_list -  sorts a doubly linked list of integers in ascending
 * order using the Insertion sort algorithm
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if ((!list || !(*list)) || !(*list)->next)
		return;
	node = (*list)->next;
	while (node)
	{
		while (node->prev && node->n < node->prev->n)
		{
			node->prev->next = node->next;
			if (node->next)
				node->next->prev = node->prev;
			decalage(node);
			if (!node->prev)
				*list = node;
			else
				node->prev->next = node;
			print_list(*list);
		}
		node = node->next;
	}
}
