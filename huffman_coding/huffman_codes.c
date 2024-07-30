#include "huffman.h"

static void codes_generator(binary_tree_node_t *node, size_t route);

/**
 * huffman_codes - builds Huffman tree and prints resulting Huffman codes for
 *                 each symbol
 * @data: char array of size size
 * @freq: array of associated frequencies of size size
 * @size: size of data and freq arrays
 * Return: 1 upon success, otherwise 0
 */
int huffman_codes(char *data, size_t *freq, size_t size)
{
	binary_tree_node_t *huffman = NULL;
	size_t route = 0;

	if (!data || !freq || !size)
		return (0);
	huffman = huffman_tree(data, freq, size);
	if (!huffman)
		return (0);
	codes_generator(huffman, route);
	return (1);
}

/**
 * codes_generator - evaluates and prints routes to each member of huffman tree
 * @node: pointer to current node in traversal sequence
 * @route: number representing necessary steps of traversal in order to
 *         reach current node. 0 bit = left step, 1 bit = right step
 */
static void codes_generator(binary_tree_node_t *node, size_t route)
{
	char node_char = 0, hit = 0;
	size_t mask = 0;

	if (!node)
		return;
	node_char = ((symbol_t *)node->data)->data;
	if (ISLEAF(node) && node_char != -1)
	{
		printf("%c: ", node_char);
		for (mask = 1UL << 63; mask; mask >>= 1)
		{
			if ((mask & route) || hit)
				putchar((mask & route) ? '1' : '0'), hit = 1;
			else if (!(mask >> 1) && !hit)
				putchar('0');
		}
		putchar('\n');
	}
	codes_generator(node->left, route << 1);
	codes_generator(node->right, (route << 1) + 1);
	free(node->data), node->data = NULL;
	free(node), node = NULL;
}
