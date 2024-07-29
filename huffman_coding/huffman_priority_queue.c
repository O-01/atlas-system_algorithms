#include "huffman.h"

int freq_cmp(void *p1, void *p2);

/**
 * huffman_priority_queue - creates priority queue for Huffman coding algorithm
 * @data: char array of size size
 * @freq: array of associated frequencies of size size
 * @size: size of data and freq arrays
 * Return: pointer to created priority queue
 */
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size)
{
	heap_t *priority_queue = NULL;
	size_t iter = 0;

	if (!data || !freq || !size)
		return (NULL);
	priority_queue = heap_create(freq_cmp);
	if (!priority_queue)
		return (NULL);
	for (; data[iter] && iter < size; ++iter)
		heap_insert(priority_queue,
			binary_tree_node(NULL, symbol_create(data[iter], freq[iter])));
	priority_queue->size = size;
	return (priority_queue);
}

/**
 * freq_cmp - compares two size_t values that correspond to freq
 * @p1: first pointer
 * @p2: second pointer
 * Return: difference between the two inputs
 */
int freq_cmp(void *p1, void *p2)
{
	return (FREQ(p1) < FREQ(p2) ? -1 : FREQ(p1) == FREQ(p2) ? 0 : 1);
}
