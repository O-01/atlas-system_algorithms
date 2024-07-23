#include "heap.h"

/**
 * heap_insert -
 * @heap:
 * @data:
 * Return:
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *add = NULL;

	if (!heap || !data)
		return (NULL);
	add = binary_tree_node(NULL, data);
	if (!add)
		return (NULL);
	if (!heap->root)
		return (heap->root ? ++heap->size, heap->root : NULL);
}
