#include "huffman.h"

static void codes_generator(binary_tree_node_t *node, char *route, int pos);

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
	char route[255] = {0};
	int pos = 0;

	if (!data || !freq || !size)
		return (0);
	huffman = huffman_tree(data, freq, size);
	if (!huffman)
		return (0);
	codes_generator(huffman, route, pos);
	return (1);
}

/**
 * codes_generator - evaluates and prints routes to each member of huffman tree
 * @node: pointer to current node in traversal sequence
 * @route: pointer to array representing necessary steps of traversal in order
 *         to reach current node. 0 bit = left step, 1 bit = right step
 * @pos: recorded position within route array
 */
static void codes_generator(binary_tree_node_t *node, char *route, int pos)
{
	char node_char = 0;

	if (!node)
		return;
	node_char = ((symbol_t *)node->data)->data;
	if (ISLEAF(node) && node_char != -1)
		route[pos] = '\0',
		printf("%c: %*s\n", node_char, pos, route);
	codes_generator(node->left, (route[pos] = '0', route), 1 + pos);
	codes_generator(node->right, (route[pos] = '1', route), 1 + pos);
	free(node->data), node->data = NULL;
	free(node), node = NULL;
}
