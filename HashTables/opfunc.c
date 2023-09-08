#include "hash.h"

void handle_collision(HashTable* table, unsigned long index, Ht_item* item)
{
	LinkedList* head = table->overflow_buckets[index];

	if (head == NULL)
	{
		/*Create the list*/
		head = allocate_list();
		head->item = item;
		table->overflow_buckets[index] = head;
		return;
	}
	else
	{
		/*Insert all the list*/
		table->overflow_buckets[index] = linkedlist_insert(head, item);
		return;
	}
}

void ht_insert(HashTable* table, char* key, char* value)
{
	Ht_item *current_item, *item;
	int index;

	/*Create the item*/
	item = create_item(key, value);
	
	/*Compute the index*/
	index = hash_function(key);

	current_item = table->items[index];

	if (current_item == NULL)
	{
		/*key does not exist*/
		if (table->count == table->size)
		{
			/*Hash Table is full*/
			printf("Error: Hash Table is full\n");
			free_item(item);
			return;
		}
		/*Insert directly*/
		table->items[index] = item;
		return;
	}
	else
	{
		/*Scenario 1: update the value*/
		if (strcmp(current_item->key, key) == 0)
		{
			strcpy(table->items[index]->value, value);
			return;
		}
		else
		{
			/*Scenario 2: Handle the collision*/
			handle_collision(table, index, item);
			return;
		}
	}

}

char* ht_search(HashTable* table, char* key)
{
	int index;
	Ht_item* item;
	LinkedList* head;

	index = hash_function(key);
	item = table->items[index];
	head = table->overflow_buckets[index];

	if (item != NULL)
	{
		if (strcmp(item->key, key) == 0)
			return item->value;

		if (head == NULL)
			return (NULL);

		item = head->item;
		head = head->next;
	}

	return NULL;
}

void ht_delete(HashTable* table, char* key)
{
	  LinkedList *curr, *node, *prev;
    /*Deletes an item from the table.*/
    int index = hash_function(key);
    Ht_item* item = table->items[index];
    LinkedList* head = table->overflow_buckets[index];

    if (item == NULL)
    {
        /*Does not exist.*/
        return;
    }
    else {
        if (head == NULL && strcmp(item->key, key) == 0)
        {
            /*Collision chain does not exist.*/
            /*Remove the item.*/
            /*Set table index to NULL.*/
            table->items[index] = NULL;
            free_item(item);
            table->count--;
            return;
        }
        else if (head != NULL)
        {
            /*Collision chain exists.*/
            if (strcmp(item->key, key) == 0)
            {
                /*Remove this item.*/
                /*Set the head of the list as the new item.*/
                free_item(item);
                node = head;
                head = head->next;
                node->next = NULL;
                table->items[index] = create_item(node->item->key, node->item->value);
                free_linkedlist(node);
                table->overflow_buckets[index] = head;
                return;
            }

            curr = head;
            prev = NULL;

            while (curr)
            {
                if (strcmp(curr->item->key, key) == 0)
                {
                    if (prev == NULL)
                    {
                        /*First element of the chain.*/
                        /*Remove the chain.*/
                        free_linkedlist(head);
                        table->overflow_buckets[index] = NULL;
                        return;
                    }
                    else
                    {
                        /*This is somewhere in the chain.*/
                        prev->next = curr->next;
                        curr->next = NULL;
                        free_linkedlist(curr);
                        table->overflow_buckets[index] = head;
                        return;
                    }
                }

                curr = curr->next;
                prev = curr;
            }
        }
    }
}
