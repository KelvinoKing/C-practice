#include "hash.h"

Ht_item* create_item(char* key, char* value)
{
	/*Creates a pointer to a new hash table item*/

	Ht_item* item;

	item = malloc(sizeof(Ht_item));
	if (item == NULL)
		return (NULL);

	item->key = malloc(strlen(key) + 1);
	item->value = malloc(strlen(value) + 1);

	strcpy(item->key, key);
	strcpy(item->value, value);

	return (item);
}
