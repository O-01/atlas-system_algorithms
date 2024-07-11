#include "rb_trees.h"

static void rebalance(rb_tree_t *add, rb_tree_t **tree);
static void rotate_left(rb_tree_t *root, rb_tree_t **tree);
static void rotate_right(rb_tree_t *root, rb_tree_t **tree);

/**
 * rb_tree_insert - inserts a value in red-black Tree
 * @tree: double pointer to root node of red-black tree for inserting the value
 * @value: value to store in the node to be inserted
 * Return: pointer to the created node, or NULL on failure
 */
rb_tree_t *rb_tree_insert(rb_tree_t **tree, int value)
{
	rb_tree_t *add = NULL, *tmp = *tree, *last = NULL;

	if (!tree)
		return (NULL);
	for (tmp = *tree; tmp; tmp = value < tmp->n ? tmp->left : tmp->right)
	{
		last = tmp;
		if (value == tmp->n)
			return (NULL);
	}
	add = rb_tree_node(last, value, RED);
	if (!add)
		return (NULL);
	if (ISROOT(add))
		*tree = add;
	else if (value < PA(add)->n)
		PA(add)->left = add;
	else if (value > PA(add)->n)
		PA(add)->right = add;
	rebalance(add, tree);
	return (add);
}

/**
 * rebalance - repaints and rotates red-black tree as necessary to accommodate
 *             newly added node
 * @add: newly added node
 * @tree: pointer to root node of red-black tree
 */
static void rebalance(rb_tree_t *add, rb_tree_t **tree)
{
	rb_tree_t *gran = GRAN(add);

	for (; PA(add) && ISRED(PA(add)) && gran; gran = GRAN(add))
	{
		if (UNCLE(add) && ISRED(UNCLE(add)))
			SETBLK(PA(add)), SETBLK(UNCLE(add)),
			SETRED(gran), add = gran;
		else
		{
			if (ISLEFT(PA(add)))
			{
				if (ISRIGHT(add))
					add = PA(add), rotate_left(add, tree);
				SETBLK(PA(add)), SETRED(gran);
				rotate_right(gran, tree);
			}
			else if (ISRIGHT(PA(add)))
			{
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
 * rotate_left - performs left-rotation on red-black tree
 * @root: pointer to root node of tree segment to be left-rotated
 * @tree: pointer to root node of red-black tree
 */
static void rotate_left(rb_tree_t *root, rb_tree_t **tree)
{
	rb_tree_t *tmp = NULL;

	if (!root)
		return;
	tmp = root->right;
	root->right = tmp->left;
	if (tmp->left)
		PA(tmp->left) = root;
	PA(tmp) = PA(root);
	if (ISROOT(tmp))
		*tree = tmp;
	else if (ISLEFT(root))
		PA(tmp)->left = tmp;
	else if (ISRIGHT(root))
		PA(tmp)->right = tmp;
	tmp->left = root;
	PA(root) = tmp;
}

/**
 * rotate_right - performs right-rotation on red-black tree
 * @root: pointer to root node of tree segment to be right-rotated
 * @tree: pointer to root node of red-black tree
 */
static void rotate_right(rb_tree_t *root, rb_tree_t **tree)
{
	rb_tree_t *tmp = NULL;

	if (!root)
		return;
	tmp = root->left;
	root->left = tmp->right;
	if (tmp->right)
		PA(tmp->right) = root;
	PA(tmp) = PA(root);
	if (ISROOT(tmp))
		*tree = tmp;
	else if (ISLEFT(root))
		PA(tmp)->left = tmp;
	else if (ISRIGHT(root))
		PA(tmp)->right = tmp;
	tmp->right = root;
	PA(root) = tmp;
}
