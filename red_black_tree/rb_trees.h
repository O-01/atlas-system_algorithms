#ifndef _RB_TREES_H_
#define _RB_TREES_H_

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * enum rb_color_e - Possible color of a Red-Black tree
 *
 * @RED: 0 -> Red node
 * @BLACK: 1 -> Black node
 * @DOUBLE_BLACK: 2 -> Double-black node (used for deletion)
 */
typedef enum rb_color_e
{
	RED = 0,
	BLACK,
	DOUBLE_BLACK
} rb_color_t;

/**
 * struct rb_tree_s - Red-Black tree node structure
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 * @color: Color of the node (RED or BLACK)
 */
typedef struct rb_tree_s
{
	int n;
	rb_color_t color;
	struct rb_tree_s *parent;
	struct rb_tree_s *left;
	struct rb_tree_s *right;
} rb_tree_t;

#define ISLEAF(x) (!(x)->left && !(x)->right)
#define ISROOT(x) (!(x)->parent)

#define HASLEFT(x) ((x)->left)
#define HASRIGHT(x) ((x)->right)

#define ISRED(x) ((x)->color == RED)
#define ISBLACK(x) ((x)->color == BLACK)
#define HASCOLOR(x) (ISRED(x) || ISBLACK(x))

/* INVALID RED-BLACK CONDITIONS */
#define REDROOT(x) (ISROOT(x) && ISRED(x))
#define NONCOLOR(x) (!HASCOLOR(x))
#define CONSEQ_RED(x) (ISRED(x) && \
	((HASLEFT(x) && ISRED((x)->left)) || (HASRIGHT(x) && ISRED((x)->right))))

rb_tree_t *rb_tree_node(rb_tree_t *parent, int value, rb_color_t color);
int rb_tree_is_valid(const rb_tree_t *tree);

#endif /* _RB_TREES_H_ */
