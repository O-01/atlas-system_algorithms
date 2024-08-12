#include "nary_trees.h"

static size_t nary_depth(nary_tree_t *node);

/**
 * 
 */
size_t nary_tree_diameter(nary_tree_t const *root)
{
	size_t high = 0, low = 0, height = 0, diameter = 0;
	nary_tree_t *current = NULL;

	if (!root)
		return (0);
	else if (!root->children)
		return (1);
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
