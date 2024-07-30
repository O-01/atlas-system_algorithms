#ifndef _HUFFMAN_H_
#define _HUFFMAN_H_

#include "heap.h"

/**
 * struct symbol_s - Stores a char and its associated frequency
 *
 * @data: The character
 * @freq: The associated frequency
 */
typedef struct symbol_s
{
	char data;
	size_t freq;
} symbol_t;

#define FREQ(x) ((symbol_t *)((binary_tree_node_t *)(x))->data)->freq
#define DATA(x) ((x)->data)

#define CHOOSE(x) (\
	FREQ(DATA((x)->left)) < FREQ(DATA((x)->right)) ? \
	FREQ(DATA((x)->left)) : FREQ(DATA((x)->right)))

#define FREQSUM(x) (FREQ(DATA(x)) + CHOOSE(x))
#define FREQS(x) (HAS_R(x) ? FREQSUM(x) : FREQ(DATA(x)))

#define TEST(x, y) (FREQ(x) + FREQ(y))

symbol_t *symbol_create(char data, size_t freq);
heap_t *huffman_priority_queue(char *data, size_t *freq, size_t size);
int huffman_extract_and_insert(heap_t *priority_queue);
binary_tree_node_t *huffman_tree(char *data, size_t *freq, size_t size);
int huffman_codes(char *data, size_t *freq, size_t size);

#endif
