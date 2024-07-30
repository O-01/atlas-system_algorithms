#include "huffman.h"

static void *_heap_extract(heap_t *heap);
static void set_mask(unsigned long *mask, unsigned long heap_size);
static void bubble_down(heap_t *heap);

/**
 * huffman_extract_and_insert - extracts two nodes of priority queue and insert
 *                              new node
 * @priority_queue: pointer to priority queue to extract from
 * Return: 1 upon success, 0 otherwise
 */
int huffman_extract_and_insert(heap_t *priority_queue)
{
	size_t add_freq = 0;
	binary_tree_node_t *left = NULL, *right = NULL, *add = NULL;

	if (!priority_queue || !priority_queue->root || priority_queue->size < 2)
		return (0);
	left = _heap_extract(priority_queue);
	right = _heap_extract(priority_queue);
	add_freq = FREQSUM(left, right);
	add = binary_tree_node(NULL, symbol_create((char)-1, add_freq));
	if (!add || !heap_insert(priority_queue, add))
		return (0);
	left->parent = add, right->parent = add;
	add->left = left, add->right = right;
	return (1);
}

/**
 * _heap_extract - extracts root from binary min heap
 * @heap: pointer to heap from which data to be extracted
 * Return: pointer to data previously stored at root of heap upon success,
 *         otherwise NULL
 */
static void *_heap_extract(heap_t *heap)
{
	binary_tree_node_t *pos = NULL, *tmp = NULL;
	unsigned long mask = 0;
	void *hold = NULL;

	if (!heap || !heap->root)
		return (NULL);
	hold = heap->root->data;
	if (ISLEAF(heap->root))
		return (free(heap->root), heap->root = NULL, --heap->size, hold);
	for (set_mask(&mask, heap->size), pos = heap->root; mask > 1; mask >>= 1)
		pos = mask & heap->size ? pos->right : pos->left;
	--heap->size;
	if (heap->size & 1)
		tmp = pos->left, pos->left = NULL;
	else
		tmp = pos->right, pos->right = NULL;
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
		if ((L_LESS(tmp) && R_LESS(tmp)) && CMP_CHILDREN(tmp) > 0)
			swap = (int *)tmp->right->data,
			tmp->right->data = tmp->data,
			tmp->data = swap,
			tmp = tmp->right;
		else if (L_LESS(tmp))
			swap = (int *)tmp->left->data,
			tmp->left->data = tmp->data,
			tmp->data = swap,
			tmp = tmp->left;
		else if (R_LESS(tmp))
			swap = (int *)tmp->right->data,
			tmp->right->data = tmp->data,
			tmp->data = swap,
			tmp = tmp->right;
		if ((!tmp->left && !tmp->right) ||
			(CMP_L(tmp) <= 0 && !tmp->right) ||
			(HAS_BOTH(tmp) && (CMP_L(tmp) <= 0 && CMP_R(tmp) <= 0) &&
			CMP_CHILDREN(tmp) < 0))
			break;
	}
}
