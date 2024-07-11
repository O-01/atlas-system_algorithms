#include "rb_trees.h"

static void rebalance(rb_tree_t *add, rb_tree_t **tree);
static void rotate_left(rb_tree_t *tree, rb_tree_t **root);
static void rotate_right(rb_tree_t *tree, rb_tree_t **root);

/**
 * rb_tree_insert - inserts a value in red-black Tree
 * @tree: double pointer to root node of red-black tree for inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *add = NULL;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = rb_tree_node(NULL, value, BLACK);
		return (*tree);
	}
	if (value < (*tree)->n)
	{
		if (!HASLEFT(*tree))
		{
			add = rb_tree_node(*tree, value, RED), PA(add)->left = add;
			return (add);
		}
		else
			add = rb_tree_insert(&(*tree)->left, value);
	}
	else if (value > (*tree)->n)
	{
		if (!HASRIGHT(*tree))
		{
			add = rb_tree_node(*tree, value, RED), PA(add)->right = add;
			return (add);
		}
		else
			add = rb_tree_insert(&(*tree)->right, value);
	}
	else
		return (NULL);
	if (!add)
		return (NULL);
	rebalance(add, tree);
	return (add);
}

/**
 * rebalance -
 */
static void rebalance(rb_tree_t *add, rb_tree_t **tree)
{
	rb_tree_t *gran = PA(add) ? GRAN(add) : NULL;

	for (; PA(add) && ISRED(PA(add)); gran = GRAN(add))
		if (gran)
		{
			if (UNCLE(add) && ISRED(UNCLE(add)))
				puts("WOAH"),
				SETBLK(PA(add)), SETBLK(UNCLE(add)),
				SETRED(gran), add = gran;
			else
			{
				puts("BWEH");
				if (ISLEFT(PA(add)))
				{
					puts("0");
					if (ISRIGHT(add))
						add = PA(add), rotate_left(add, tree);
					SETBLK(PA(add)), SETRED(gran);
					rotate_right(gran, tree);
				}
				else if (ISRIGHT(PA(add)))
				{
					puts("1");
					if (ISLEFT(add))
						add = PA(add), rotate_right(add, tree);
					SETBLK(PA(add)), SETRED(gran);
					rotate_left(gran, tree);
				}
			}
		}
	SETBLK(*tree);
}

/**
 * rotate_left - performs left-rotation on binary tree
 * @tree: pointer to root node of tree segment to be left-rotated
 * @root: pointer to root node of binary search tree
 */
static void rotate_left(rb_tree_t *tree, rb_tree_t **root)
{
	rb_tree_t *tmp = NULL;

	if (!tree)
		return;
	tmp = tree->right;
	tree->right = tmp->left;
	if (tmp->left)
		PA(tmp->left) = tree;
	PA(tmp) = PA(tree);
	if (ISROOT(tmp))
		*root = tmp;
	else if (ISLEFT(tree))
		PA(tmp)->left = tmp;
	else if (ISRIGHT(tree))
		PA(tmp)->right = tmp;
	tmp->left = tree;
	PA(tree) = tmp;
}

/**
 * rotate_right - performs right-rotation on binary tree
 * @tree: pointer to root node of tree segment to be right-rotated
 * @root: pointer to root node of binary search tree
 */
static void rotate_right(rb_tree_t *tree, rb_tree_t **root)
{
	rb_tree_t *tmp = NULL;

	if (!tree)
		return;
	tmp = tree->left;
	tree->left = tmp->right;
	if (tmp->right)
		PA(tmp->right) = tree;
	PA(tmp) = PA(tree);
	if (ISROOT(tmp))
		*root = tmp;
	else if (ISLEFT(tree))
		PA(tmp)->left = tmp;
	else if (ISRIGHT(tree))
		PA(tmp)->right = tmp;
	tmp->right = tree;
	PA(tree) = tmp;
}
