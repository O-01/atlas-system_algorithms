#include "nary_trees.h"

/**
 * path_exists - checks if path exists in N-ary tree
 * @root: pointer to root node of N-ary tree
 * @path: NULL terminated array of strings, each successive member of which
 *        represents content one level deeper into N-ary tree
 * Return: 1 if all elements of path are present in N-ary tree and if each
 *         member of path exists as child of previous member in succession,
 *         otherwise 0
 */
int path_exists(nary_tree_t const *root, char const * const *path)
{
	nary_tree_t *current = NULL;
	static int track;

	if ((!root || !path) && !track)
		return (0);
	if (!*path)
		return (1);
	else if (track && !root)
		return (0);
	++track;
	for (current = (n_t_t *)&root->content; current; current = current->next)
		if (!strncmp(current->content, *path, strlen(*path)) &&
			path_exists(current->children, path + 1))
			return (1);
	return (0);
}
