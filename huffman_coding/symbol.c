#include "huffman.h"

/**
 * symbol_create - creates symbol_t data structure
 * @data: data to be stored in newly created symbol structure
 * @freq: frequency associated with newly created symbol structure
 * Return: pointer to created symbol structure upon success, otherwise NULL
 */
symbol_t *symbol_create(char data, size_t freq)
{
	symbol_t *add = NULL;

	if (!data || !freq)
		return (NULL);
	add = calloc(1, sizeof(symbol_t));
	if (!add)
		return (NULL);
	add->data = data;
	add->freq = freq;
	return (add);
}
