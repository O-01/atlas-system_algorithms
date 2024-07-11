#include <stdlib.h>
#include <stdio.h>
#include "rb_trees.h"

void rb_tree_print(const rb_tree_t *tree);
static void freedom(rb_tree_t **tree);

/**
 * main - Entry point
 *
 * Return: 0 on success
 */
int main(void)
{
    rb_tree_t *root;
    rb_tree_t *node;

    root = NULL;
    /* node = rb_tree_insert(&root, 98);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 402);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 512);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 12);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 46);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 128);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 256);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 1);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 128);
    printf("Node should be nil -> %p\n", (void *)node);
    node = rb_tree_insert(&root, 624);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 780);
    printf("Inserted: %d\n", node->n); */
    node = rb_tree_insert(&root, 43);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 34);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 65);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 13);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 46);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 128);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 256);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 1);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 128);
    printf("Node should be nil -> %p\n", (void *)node);
    node = rb_tree_insert(&root, 624);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    node = rb_tree_insert(&root, 780);
    printf("Inserted: %d\n", node->n);
    rb_tree_print(root);
    freedom(&root);
    return (0);
}

/**
 * freedom - frees red-black tree
 * @tree: red-black tree to be freed
 */
static void freedom(rb_tree_t **tree)
{
    if (!*tree)
        return;
    freedom(&(*tree)->left);
    freedom(&(*tree)->right);
    free(*tree), *tree = NULL;
}
