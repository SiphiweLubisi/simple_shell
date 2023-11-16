#include "shell.h"

/**
 * bfree - frees the pointer and NULLs the address
 * @ptr: the address of the pointer to be freed
 *
 * Return: 1 if freed, 0 if otherwise.
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
