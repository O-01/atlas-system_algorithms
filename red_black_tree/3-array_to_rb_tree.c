#include "rb_trees.h"

/**
 * array_to_rb_tree - builds red-black tree from array
 * @array: pointer to first element of array to be converted
 * @size: number of elements in array
 * Return: pointer to root of created red-black tree upon success, otherwise
 *         NULL
 */
rb_tree_t *array_to_rb_tree(int *array, size_t size)
{
	size_t iter = 0;
	rb_tree_t *tree = NULL;

	if (!array || !size)
		return (NULL);
	for (; iter < size; ++iter)
		rb_tree_insert(&tree, array[iter]);
	return (tree);
}
