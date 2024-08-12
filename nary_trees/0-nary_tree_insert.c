#include "nary_trees.h"

/**
 * nary_tree_insert - inserts node into N-ary tree
 * @parent: pointer to parent node
 * @str: string to be stored in created node, must be duplicated
 * Return: pointer to created node upon success, otherwise NULL;
 */
nary_tree_t *nary_tree_insert(nary_tree_t *parent, char const *str)
{
	nary_tree_t *add = NULL;

	add = calloc(1, sizeof(nary_tree_t));
	if (!add)
		return (NULL);
	add->content = strdup(str);
	add->parent = parent;
	add->nb_children = 0;
	add->children = NULL;
	if (!parent)
		return (add->next = NULL, add);
	add->next = parent->children;
	parent->children = add;
	++parent->nb_children;
	return (add);
}
