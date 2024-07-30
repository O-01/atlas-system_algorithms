#include <stdlib.h>
#include <stdio.h>
#include "heap.h"
#include "huffman.h"

void binary_tree_print(const binary_tree_node_t *heap, int (*print_data)(char *, void *));
void free_data(void *data);

/**
 * symbol_print - Prints a symbol structure
 *
 * @buffer: Buffer to print into
 * @data: Pointer to a node's data
 *
 * Return: Number of bytes written in buffer
 */
int symbol_print(char *buffer, void *data)
{
    symbol_t *symbol;
    char c;
    int length;

    symbol = (symbol_t *)data;
    c = symbol->data;
    if (c == -1)
        c = '$';
    length = sprintf(buffer, "(%c/%lu)", c, symbol->freq);
    return (length);
}

/**
 * nested_print - Prints a symbol structure stored in a nested node
 *
 * @buffer: Buffer to print into
 * @data: Pointer to a node's data
 *
 * Return: Number of bytes written in buffer
 */
int nested_print(char *buffer, void *data)
{
    binary_tree_node_t *nested;
    symbol_t *symbol;
    char c;
    int length;

    nested = (binary_tree_node_t *)data;
    symbol = (symbol_t *)nested->data;
    c = symbol->data;
    if (c == -1)
        c = '$';
    length = sprintf(buffer, "(%c/%lu)", c, symbol->freq);
    return (length);
}

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
    char data[] = {
        'a', 'b', 'c', 'd', 'e', 'f'
    };
    size_t freq[] = {
        6, 11, 12, 13, 16, 36
    };
    size_t size = sizeof(data) / sizeof(data[0]);
	heap_t *priority_queue = NULL;
	binary_tree_node_t *root = NULL;

    priority_queue = huffman_priority_queue(data, freq, size);
    if (!priority_queue)
    {
        fprintf(stderr, "Failed to create priority queue\n");
        return (EXIT_FAILURE);
    }
    binary_tree_print(priority_queue->root, nested_print);
    printf("\n");

    heap_delete(priority_queue, free_data), priority_queue = NULL;
    root = huffman_tree(data, freq, size);
    if (!root)
    {
        fprintf(stderr, "Failed to build Huffman tree\n");
        return (EXIT_FAILURE);
    }
    binary_tree_print(root, symbol_print);

    free_data(root);

    if (!huffman_codes(data, freq, size))
    {
        fprintf(stderr, "Failed to get Huffman codes\n");
        return (EXIT_FAILURE);
    }

    return (EXIT_SUCCESS);
}

void free_data(void *data)
{
    if (!data)
        return;
    free_data(((binary_tree_node_t *)data)->left);
    free_data(((binary_tree_node_t *)data)->right);
    free((symbol_t *)((binary_tree_node_t *)data)->data);
    ((binary_tree_node_t *)data)->data = NULL;
    free(data), data = NULL;
}
