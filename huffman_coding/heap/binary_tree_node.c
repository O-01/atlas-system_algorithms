#include "heap.h"

/**
 * binary_tree_node - creates generic binary tree node
 * @parent: pointer to parent node of node to be created
 * @data: data to be stored in node
 * Return: pointer to created node upon success, otherwise NULL
 */
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data)
{
	binary_tree_node_t *add = NULL;

	add = calloc(1, sizeof(binary_tree_node_t));
	if (!add)
		return (NULL);
	add->data = data;
	add->left = NULL;
	add->right = NULL;
	add->parent = parent;
	return (add);
}
