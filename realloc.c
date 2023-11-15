#include "shell.h"

/**
 **_memset - fills memory with a constant byte
 *@t: the pointer to the memory area
 *@c: the byte to fill *s with
 *@m: the amount of bytes to be filled
 *Return: (s) a pointer to the memory area s
 */
char *_memset(char *t, char c, unsigned int m)
{
	unsigned int i;

	for (i = 0; i < m; i++)
		t[i] = c;
	return (t);
}

/**
 * ffree - frees a string of strings
 * @qq: string of strings
 */
void ffree(char **qq)
{
	char **b = qq;

	if (!qq)
		return;
	while (*qq)
		free(*qq++);
	free(b);
}

/**
 * _realloc - reallocates a block of memory
 * @ptr: pointer to previous malloc'ated block
 * @old_size: byte size of previous block
 * @new_size: byte size of new block
 *
 * Return: pointer to da ol'block nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *q;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_size)
		return (ptr);

	q = malloc(new_size);
	if (!q)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		q[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (q);
}
