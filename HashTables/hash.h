#ifndef HASH_H
#define HASH_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CAPACITY 50000 /*Size of the hash table*/

/*Define the hash table item*/
typedef struct Ht_item
{
	char *key;
	char *value;
} Ht_item;

/*Define the hash table*/
typedef struct HashTable
{
	Ht_item** item;
	int count;
	int size;
} HashTable;

unsigned long hash_function(char *str);
Ht_item* create_item(char* key, char* value);
HashTable* create_table(int size);
void free_item(Ht_item* item);
void free_table(HashTable* table);
#endif /*HASH_H*/
