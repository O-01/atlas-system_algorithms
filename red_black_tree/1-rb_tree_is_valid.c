#include "rb_trees.h"

static int black_paths(const rb_tree_t *tree, int count);
static int is_bst(const rb_tree_t *tree, const int *val);

/**
 * rb_tree_is_valid - checks if binary tree is valid red-black tree
 * @tree: pointer to root node of tree to be checked
 * Return: 1 upon valid, 0 upon invalid or NULL input tree
 */
int rb_tree_is_valid(const rb_tree_t *tree)
{
	if (!tree || REDROOT(tree) || NONCOLOR(tree) || CONSEQ_RED(tree))
		return (0);
	if (!is_bst(tree->left, &tree->n) || !is_bst(tree->right, &tree->n))
		return (0);
	if (!black_paths(tree, 0))
		return (0);
	if ((tree->left && !rb_tree_is_valid(tree->left)) ||
		(tree->right && !rb_tree_is_valid(tree->right)))
		return (0);
	return (1);
}

/**
 * black_paths - evaluates whether all paths from root have equal black node
 *               counts
 * @tree: root of tree to be evaluated
 * @count: recorded black node count in path
 * Return: 1 if black node count in left and right paths equal, 0 otherwise
 */
static int black_paths(const rb_tree_t *tree, int count)
{
	if (!tree)
		return (count);
	if (ISBLACK(tree))
		++count;
	return (black_paths(tree->left, count) == black_paths(tree->right, count));
}

/**
 * is_bst - evaluates whether binary tree is binary search tree
 * @tree: tree to be evaluated
 * @val: value stored in most recently evaluated node
 * Return: 1 if tree is binary search tree, 0 otherwise
 */
static int is_bst(const rb_tree_t *tree, const int *val)
{
	if (!tree)
		return (1);
	if (!is_bst(tree->left, val) || &tree->n <= val)
		return (0);
	val = &tree->n;
	return (is_bst(tree->right, val));
}
