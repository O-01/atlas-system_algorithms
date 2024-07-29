#ifndef _HEAP_H_
#define _HEAP_H_

#include <stdio.h>
#include <stdlib.h>

/**
 * struct binary_tree_node_s - Binary tree node data structure
 *
 * @data: Data stored in a node
 * @left: Pointer to the left child
 * @right: Pointer to the right child
 * @parent: Pointer to the parent node
 */
typedef struct binary_tree_node_s
{
	void *data;
	struct binary_tree_node_s *left;
	struct binary_tree_node_s *right;
	struct binary_tree_node_s *parent;
} binary_tree_node_t;

/**
 * struct heap_s - Heap data structure
 *
 * @size: Size of the heap (number of nodes)
 * @data_cmp: Function to compare two nodes data
 * @root: Pointer to the root node of the heap
 */
typedef struct heap_s
{
	size_t size;
	int (*data_cmp)(void *, void *);
	binary_tree_node_t *root;
} heap_t;

#define ISLEAF(x) (!(x)->left && !(x)->right)
#define ISROOT(x) (!(x)->parent)

#define HAS_L(x) ((x)->left)
#define HAS_R(x) ((x)->right)
#define HAS_BOTH(x) (HAS_L(x) && HAS_R(x))

#define ISLEFT(x) ((x) == (x)->parent->left)
#define ISRIGHT(x) ((x) == (x)->parent->right)

#define CMP_L(x) (heap->data_cmp((x)->data, (x)->left->data))
#define CMP_R(x) (heap->data_cmp((x)->data, (x)->right->data))

#define L_LESS(x) (HAS_L(tmp) && CMP_L(tmp) > 0)
#define R_LESS(x) (HAS_R(tmp) && CMP_R(tmp) > 0)

#define CMP_CHILDREN(x) (\
	heap->data_cmp((x)->left->data, (x)->right->data))

heap_t *heap_create(int (*data_cmp)(void *, void *));
binary_tree_node_t *binary_tree_node(binary_tree_node_t *parent, void *data);
binary_tree_node_t *heap_insert(heap_t *heap, void *data);
void *heap_extract(heap_t *heap);
void heap_delete(heap_t *heap, void (*free_data)(void *));

#endif
