#include "heap.h"

static void set_mask(unsigned long *mask, unsigned long heap_size);
static void bubble_down(heap_t *heap);

/**
 * heap_extract - extracts root from binary min heap
 * @heap: pointer to heap from which data to be extracted
 * Return: pointer to data previously stored at root of heap upon success,
 *         otherwise NULL
 */
void *heap_extract(heap_t *heap)
{
	binary_tree_node_t *pos = NULL, *tmp = NULL;
	unsigned long mask = 0;
	void *hold = NULL;

	if (!heap || !heap->root || !heap->size)
		return (NULL);
	--heap->size;
	if (ISLEAF(heap->root))
		return (free(heap->root), heap->root = NULL);
	for (set_mask(&mask, heap->size), pos = heap->root; mask > 1; mask >>= 1)
		pos = mask & heap->size ? pos->right : pos->left;
	if (heap->size & 1)
		tmp = pos->left, pos->left = NULL;
	else
		tmp = pos->right, pos->right = NULL;
	hold = heap->root->data;
	heap->root->data = (int *)tmp->data, free(tmp), tmp = NULL;
	bubble_down(heap);
	return (hold);
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

/**
 * bubble_down - performs bubble down operation to restore binary min heap
 *               status
 * @heap: pointer to heap structure to be restored as necessary, contains data
 *        comparison function to be used
 */
static void bubble_down(heap_t *heap)
{
	binary_tree_node_t *tmp = NULL;
	void *swap = NULL;

	for (tmp = heap->root;;)
	{
		if (HAS_L(tmp) && heap->data_cmp(tmp->data, tmp->left->data) > 0)
			swap = (int *)tmp->left->data,
			tmp->left->data = tmp->data,
			tmp->data = swap,
			tmp = tmp->left;
		else if (HAS_R(tmp) && heap->data_cmp(tmp->data, tmp->right->data) > 0)
			swap = (int *)tmp->right->data,
			tmp->right->data = tmp->data,
			tmp->data = swap,
			tmp = tmp->right;
		if (!tmp->left && !tmp->right)
			break;
	}
}
