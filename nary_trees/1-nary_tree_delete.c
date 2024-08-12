#include "nary_trees.h"

/**
 * nary_tree_delete - deallocates entire N-ary tree
 * @tree: N-ary tree to be deleted
 */
void nary_tree_delete(nary_tree_t *tree)
{
	if (!tree)
		return;
	nary_tree_delete(tree->children);
	nary_tree_delete(tree->next);
	FREE_0(tree->content), FREE_0(tree);
}
