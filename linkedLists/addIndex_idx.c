#include "lists.h"

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *current;
	listint_t *new_node;
	unsigned int i = 0;

	current = *head;
	new_node = malloc(sizeof(listint_t));
	if (new_node == NULL)
		return (NULL);
	
	if (idx == 0)
	{
		new_node->n = n;
		new_node->next = current;
		*head = new_node;
		return (new_node);
	}

	while (i < (idx-1))
	{
		if (current->next == NULL)
			return (NULL);
		current = current->next;
		i++;
	}

	new_node->n = n;
	new_node->next = current->next;
	current->next = new_node;

	return (new_node);
}
