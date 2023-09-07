#include "hash.h"

void free_item(Ht_item* item)
{
	/*Free an item*/
	free(item->key);
	free(item->value);
	free(item);
}

void free_table(HashTable* table)
{
	/*Free the table*/

	int i;
	Ht_item* item;

	for (i = 0; i < table->size; i++)
	{
		item = table->items[i];

		if (item)
			free_item(item);
	}

	free(table->items);
	free(table);
}
