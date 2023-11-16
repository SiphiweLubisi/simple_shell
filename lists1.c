#include "shell.h"

/**
 * list_len - determines length of linked list
 * @a: the pointer to the first node
 *
 * Return: the size of list
 */

size_t list_len(const list_t *a)
{
	size_t i = 0;

	while (a)
	{
		a = a->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - returns an array of strings
 * @head: the pointer to first node
 *
 * Return: the array of strings
 */

char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - prints all the elements of the list_t
 * @a: the pointer to the first node
 *
 * Return: the size of list
 */

size_t print_list(const list_t *a)
{
	size_t i = 0;

	while (a)
	{
		_puts(convert_number(a->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(a->str ? a->str : "(nil)");
		_puts("\n");
		a = a->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - returns the node whose string starts with the prefix
 * @node: the pointer to the list head
 * @prefix: the string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */

list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - getting the index of a node
 * @head: the pointer to list head
 * @node: the pointer to the node
 *
 * Return: index of node or -1
 */

ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
