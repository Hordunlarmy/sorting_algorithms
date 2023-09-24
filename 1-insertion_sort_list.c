#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *              using the insertion sort algorithm.
 * @list: A pointer to the head of the list.
 *
 * Return: nothing.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *insert, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (cur = (*list)->next; cur != NULL; cur = tmp)
	{
		tmp = cur->next;
		insert = cur->prev;
		while (insert != NULL && cur->n < insert->n)
		{
			swap_node(list, &insert, cur);
			print_list((const listint_t *)*list);
		}
	}
}
/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @head: A pointer to the head of the list.
 * @node1: A pointer to the first node.
 * @node2: A pointer to the second node.
 */
void swap_node(listint_t **head, listint_t **node1, listint_t *node2)
{
	(*node1)->next = node2->next;
	if (node2->next != NULL)
		node2->next->prev = *node1;
	node2->prev = (*node1)->prev;
	node2->next = *node1;
	if ((*node1)->prev != NULL)
		(*node1)->prev->next = node2;
	else
		*head = node2;
	(*node1)->prev = node2;
	*node1 = node2->prev;
}
