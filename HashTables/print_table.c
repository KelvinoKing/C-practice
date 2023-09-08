#include "hash.h"

void print_table(HashTable* table)
{
	/*Prints all info in the table*/

	int i;

	printf("\nHash Table\n--------------------------------\n");

	for (i = 0; i < table->size; i++)
	{
		if (table->items[i])
		{
			printf("Index: %d,   Key: %s,   Value: %s\n", i, table->items[i]->key,
					table->items[i]->value);
		}
	}

	printf("---------------------------------------------\n\n");
}

void print_search(HashTable* table, char* key)
{
	char* val;

	if ((val = ht_search(table, key)) == NULL)
	{
		printf("Key: %s  does not exist\n", key);
		return;
	}
	else
	{
		printf("Key: %s,  Value: %s\n", key, val);
	}
}
