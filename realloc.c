#include "shell.h"

/**
 **_memset - fills the memory with a constant byte
 *@g: the pointer to the memory area
 *@b: the byte to fill *g with
 *@n: the amount of bytes to be filled
 *Return: (g) a pointer to the memory area g
 */
char *_memset(char *g, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		g[i] = b;
	return (g);
}

/**
 * ffree - free the string of strings
 * @pp: string of strings
 */

void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocates the memory block
 * @ptr: the pointer to the previous malloc block
 * @old_size: the byte size of the previous block
 * @new_size: the byte size of the new block
 *
 * Return: pointer to da ol'block nameen.
 */

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
