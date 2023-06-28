#include "shell.h"

/**
 * bfree - frees a pointer and sets the address to NULL
 * @ptr: address of the pointer to deallocate
 *
 * Return: 1 if deallocated, else 0
 */
int bfree(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (0);
}
