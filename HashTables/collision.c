#include "hash.h"

LinkedList* allocate_list(void)
{
	/*Allocates memory for a LinkedList pointer*/
	LinkedList *list;

	list = malloc(sizeof(LinkedList));
	return (list);
}

LinkedList* linkedlist_insert(LinkedList* list, Ht_item* item)
{
	LinkedList *node, *head, *temp;
	/*Inserts the item onto the LinkedList*/
	if (!list)
	{
		head = allocate_list();
		head->item = item;
		head->next = NULL;
		list = head;
		return (list);
	}
	else if (list->next == NULL)
	{
		node = allocate_list();
		node->item = item;
		node->next = NULL;
		list->next = node;
		return (list);
	}

	temp = list;
	while (temp->next->next)
	{
		temp = temp->next;
	}

	node = allocate_list();
	node->item = item;
	node->next = NULL;
	temp->next = node;
	return (list);
}

Ht_item* linkedlist_remove(LinkedList* list)
{
	LinkedList *node, *temp;
	Ht_item* it;
	/*Remove the head from the list*/
	/*Returns the item of the popped element*/

	if (!list)
		return (NULL);

	if (!list->next)
		return (NULL);

	node = list->next;
	temp = list;
	temp->next = NULL;
	list = node;
	it = NULL;
	memcpy(temp->item, it, sizeof(Ht_item));
	free(temp->item->key);
	free(temp->item->value);
	free(temp->item);
	free(temp);
	return (it);
}

void free_linkedlist(LinkedList* list)
{
	LinkedList* temp = list;

	while(list)
	{
		temp = list;
		list = list->next;
		free(temp->item->key);
		free(temp->item->value);
		free(temp->item);
		free(temp);
	}
}

LinkedList** create_overflow_buckets(HashTable* table)
{
	/*Create the overfllow buckets; an array of LinkedList*/
	int i;
	LinkedList** buckets = calloc(table->size, sizeof(LinkedList*));

	for (i = 0; i < table->size; i++)
		buckets[i] = NULL;

	return (buckets);
}

void free_overflow_buckets(HashTable* table)
{
	/*Free all the overflow buckets*/
	int i;
	LinkedList** buckets = table->overflow_buckets;

	for (i = 0; i < table->size; i++)
		free_linkedlist(buckets[i]);

	free(buckets);
}
