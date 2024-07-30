#include "huffman.h"

/**
 * huffman_tree - builds Huffman tree
 * @data: char array of size size
 * @freq: array of associated frequencies of size size
 * @size: size of data and freq arrays
 * Return: pointer to root of Huffman tree upon success, otherwise NULL
 */
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *root = NULL;
	heap_t *priority_queue = NULL;

	if (!data || !freq || !size)
		return (NULL);
	priority_queue = huffman_priority_queue(data, freq, size);
	if (!priority_queue)
		return (NULL);
	while (priority_queue->size > 1)
		if (!huffman_extract_and_insert(priority_queue))
			return (NULL);
	root = heap_extract(priority_queue);
	heap_delete(priority_queue, NULL);
	return (root);
}
