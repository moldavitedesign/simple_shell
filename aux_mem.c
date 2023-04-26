#include <stdlib.h>

/**
 * _copy_mem - Copies data from one memory location to another
 * @dest: Destination memory pointer
 * @src: Source memory pointer
 * @n: Number of bytes to be copied
 *
 * Return: None
 */
void _copy_mem(void *dest, const void *src, size_t n)
{
	char *csrc = (char *)src;
	char *cdest = (char *)dest;

	for (size_t i = 0; i < n; i++)
		cdest[i] = csrc[i];
}

/**
 * _realloc_mem - Reallocates a memory block with the new size
 * @ptr: Pointer to the memory previously allocated
 * @old_size: Current size of the memory block
 * @new_size: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block
 * If new_size == old_size, returns ptr without changes.
 * If malloc fails, returns NULL.
 */
void *_realloc_mem(void *ptr, size_t old_size, size_t new_size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_copy_mem(new_ptr, ptr, new_size);
	else
		_copy_mem(new_ptr, ptr, old_size);

	free(ptr);
	return (new_ptr);
}

/**
 * _realloc_double_ptr - Reallocates a memory block of a double pointer
 * @ptr: Double pointer to the memory previously allocated
 * @old_size: Current size of the memory block
 * @new_size: New size of the memory block
 *
 * Return: Pointer to the reallocated memory block
 * If new_size == old_size, returns ptr without changes.
 * If malloc fails, returns NULL.
 */
char **_realloc_double_ptr(char **ptr, size_t old_size, size_t new_size)
{
	char **new_ptr;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	new_ptr = malloc(sizeof(char *) * new_size);
	if (new_ptr == NULL)
		return (NULL);

	for (size_t i = 0; i < old_size; i++)
		new_ptr[i] = ptr[i];

	free(ptr);

	return (new_ptr);
}

