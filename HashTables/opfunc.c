#include "hash.h"

void handle_collision(HashTable* table, Ht_item* item)
{
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
			handle_collision(table, item);
			return;
		}
	}

}

char* ht_search(HashTable* table, char* key)
{
	int index;
	Ht_item* item;

	index = hash_function(key);
	item = table->items[index];

	if (item != NULL)
	{
		if (strcmp(item->key, key) == 0)
			return item->value;
	}

	return NULL;
}
