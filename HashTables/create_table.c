#include "hash.h"

HashTable* create_table(int size)
{
	/*Creates a new hash table*/

	HashTable* table;
	int i;

	table = malloc(sizeof(HashTable));
	if (table == NULL)
		return (NULL);

	table->size = size;
	table->count = 0;
	table->items = calloc(table->size, sizeof(Ht_item*));
	if (table->items == NULL)
		return (NULL);

	for (i = 0; i < table->size; i++)
		table->items[i] = NULL;

	table->overflow_buckets = create_overflow_buckets(table);
	return (table);
}
