#include "rb_trees.h"

/**
 * rb_tree_node - creates red-black tree node
 * @parent: pointer to parent node of node to be created, may be NULL
 * @value: value to be held by created node
 * @color: color of node to be created
 * Return: pointer to newly created node, NULL upon failure
 */
rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color)
{
	rb_tree_t *add = NULL;

	add = calloc(1, sizeof(rb_tree_t));
	if (!add)
		return (NULL);
	add->parent = parent;
	add->n = value;
	add->color = color;
	add->left = NULL;
	add->right = NULL;
	return (add);
}
