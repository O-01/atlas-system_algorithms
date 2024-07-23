#include "heap.h"

/**
 * heap_create - creates heap data structure
 * @data_cmp: pointer to comparison function to be stored
 *     takes two void pointers, each being data stored in nodes
 *     returns difference between data stored at two nodes
 * Return: pointer to created heap_t data structure
 */
heap_t *heap_create(int (*data_cmp)(void *, void *))
{
	heap_t *add = NULL;

	if (!data_cmp)
		return (NULL);
	add = calloc(1, sizeof(heap_t));
	if (!add)
		return (NULL);
	add->size = 0;
	add->data_cmp = data_cmp;
	add->root = NULL;
	return (add);
}
