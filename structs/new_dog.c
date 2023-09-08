#include "dog.h"
#include <stdlib.h>

int _strlen(char *s)
{
	int i = 0;
	int count = 0;

	while (*(s + 1) != '\0')
	{
		count++;
		i++;
	}
	return (count);
}

dog_t *new_dog(char *name, float age, char *owner)
{
	int i = 0;
	dog_t *new_dog;

	new_dog = malloc(sizeof(dog_t));
	if (new_dog == NULL)
		return (NULL);

	new_dog->age = age;
	
	/*Now we want to allocate memory for name*/
	new_dog->name = malloc(sizeof(new_dog->name) * _strlen(name));
	if (new_dog->name == NULL)
	{
		free(new_dog);
		return (NULL);
	}

	new_dog->owner = malloc(sizeof(new_dog->owner) * _strlen(name));
	if (new_dog->owner == NULL)
	{
		free(new_dog->name);
		free(new_dog);
		return (NULL);
	}

	while (i <= _strlen(name))
	{
		new_dog->name[i] = name[i];
		i++;
	}

	i = 0;
	while (i <= _strlen(owner))
	{
		new_dog->owner[i] = owner[i];
		i++;
	}
	return (new_dog);
}
