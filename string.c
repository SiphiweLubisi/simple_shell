#include "shell.h"

/**
 * _strlen - return the length of string
 * @s: the string whose length to check
 *
 * Return: integer the length of string
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (0);

	while (*s++)
		i++;
	return (i);
}

/**
 * _strcmp - performs the lexicogarphic comparison to strings
 * @s1: the first strang
 * @s2: the second strang
 *
 * Return: false if s1 < s2, correct if s1 > s2, zero if s1 == s2
 */

int _strcmp(char *s1, char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else
		return (*s1 < *s2 ? -1 : 1);
}

/**
 * starts_with - check if the needle starts with haystack
 * @haystack: the string to search
 * @needle: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */

char *starts_with(const char *haystack, const char *needle)
{
	while (*needle)
		if (*needle++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates the two strings
 * @dest: the destination buffer
 * @src: the source buffer
 *
 * Return: the pointer to the destination buffer
 */

char *_strcat(char *dest, char *src)
{
	char *ret = dest;

	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = *src;
	return (ret);
}
