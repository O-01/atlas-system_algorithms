#include "nary_trees.h"

static size_t get_depth(
	n_t_t const *root,
	void (*action)(n_t_t const *node, size_t depth),
	size_t deep);

/**
 * nary_tree_traverse - goes through N-ary tree, node by node
 * @root: pointer to root node of tree to traverse
 * @action: pointer to function to execute for each node being traversed, its
 *          arguments are:
 *               node: pointer to node being traversed
 *               depth: depth of node being traversed
 * Return: largest depth of tree pointed to by root
 */
size_t nary_tree_traverse(
	n_t_t const *root, void (*action)(n_t_t const *node, size_t depth))
{
	size_t depth = 0;

	if (!root)
		return (0);
	return (get_depth(root, action, depth));
}

/**
 * get_depth - traverse N-ary tree and its children/siblings recursively
 * @root: pointer to root node of subtree to traverse
 * @action: pointer to function to execute for each node being traversed, its
 *          arguments are:
 *               node: pointer to node being traversed
 *               depth: depth of node being traversed
 * @deep: current depth within N-ary tree
 * Return: current depth within N-ary tree
 */
static size_t get_depth(
	n_t_t const *root,
	void (*action)(n_t_t const *node, size_t depth),
	size_t deep)
{
	if (!root)
		return (deep);
	action(root, deep);
	get_depth(root->children, action, deep + 1);
	get_depth(root->next, action, deep);
	return (deep);
}
