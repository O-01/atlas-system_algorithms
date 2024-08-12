#include "nary_trees.h"

static size_t nary_depth(nary_tree_t *node);

/**
 * nary_tree_diameter - computes diameter of N-ary tree
 * @root: pointer to root node of tree to compute diameter of
 * Return: diameter of tree pointed to by root
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t high = 0, low = 0, height = 0, diameter = 0;
	nary_tree_t *current = NULL;

	if (!root)
		return (0);
	for (current = root->children; current; current = current->next)
	{
		height = nary_depth(current);
		if (height > high)
			low = high, high = height;
		else if (height > low)
			low = height;
		diameter = MAX(diameter, nary_tree_diameter(current));
	}
	return (MAX(diameter, high + low + 1));
}

/**
 * nary_depth - calculates depth of current node within N-ary tree
 * @node: pointer to current node
 * Return: depth of current node within N-ary tree
 */
static size_t nary_depth(nary_tree_t *node)
{
	size_t depth = 0;
	nary_tree_t *current = NULL;

	if (!node)
		return (0);
	for (current = node->children; current; current = current->next)
		depth = MAX(depth, nary_depth(current));
	return (depth + 1);
}
