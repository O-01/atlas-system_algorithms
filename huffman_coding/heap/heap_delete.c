#include "heap.h"

static void freedom(binary_tree_node_t *root, void (*free_data)(void *));

/**
 * heap_delete - deallocates memory related to input heap
 * @heap: pointer to heap to be deleted
 * @free_data: pointer to function used to free content of node(s)
 */
void heap_delete(heap_t *heap, void (*free_data)(void *))
{
	if (!heap)
		return;
	freedom(heap->root, free_data);
	free(heap), heap = NULL;
}

/**
 * freedom - frees binary heap nodes recursively
 * @root: pointer to root node of binary heap or heap segment
 * @free_data: pointer to function used to free content of node(s)
 */
static void freedom(binary_tree_node_t *root, void (*free_data)(void *))
{
	if (!root)
		return;
	freedom(root->left, free_data);
	freedom(root->right, free_data);
	if (free_data)
		free_data(root->data);
	free(root), root = NULL;
}
