#include "lists.h"

int pop_listint(listint_t **head)
{
	listint_t *temp_node;
	int n;

	if (head == NULL)
		return (0);

	if (*head == NULL)
		return (0);

	temp_node = (*head)->next;
	n = (*head)->n;
	free(*head);
	*head = temp_node;

	return (n);
}
