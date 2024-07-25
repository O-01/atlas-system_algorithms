#include "heap.h"

static void set_mask(unsigned long *mask, unsigned long heap_size);

/**
 * heap_insert - inserts value into binary min heap
 * @heap: pointer to heap into which new node to be inserted
 * @data: pointer containing data to be stored in new node
 * Return: pointer to created node upon success, otherwise NULL
 */
binary_tree_node_t *heap_insert(heap_t *heap, void *data)
{
	binary_tree_node_t *add = NULL, *pos = NULL;
	unsigned long mask = 0;
	int *tmp = NULL;

	if (!heap || !data)
		return (NULL);
	add = binary_tree_node(NULL, data);
	if (!add)
		return (NULL);
	++heap->size;
	if (!heap->root)
		return (heap->root = add);
	for (set_mask(&mask, heap->size), pos = heap->root; mask > 1; mask >>= 1)
		pos = mask & heap->size ? pos->right : pos->left;
	if ((heap->size - 1) & 1)
		pos->left = add;
	else
		pos->right = add;
	add->parent = pos;
	while (add->parent && heap->data_cmp(add->data, add->parent->data) < 0)
		tmp = (int *)add->parent->data,
		add->parent->data = (int *)add->data,
		add->data = tmp,
		add = add->parent;
	return (add);
}

/**
 * set_mask - sets mask to most significant bit of input shifted right one bit
 * @mask: pointer to mask to be set
 * @input: reference data for setting of mask
 */
static void set_mask(unsigned long *mask, unsigned long input)
{
	for (*mask = 1UL << 63; !(*mask & input); *mask >>= 1)
		;
	*mask >>= 1;
}
