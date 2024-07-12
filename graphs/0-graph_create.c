#include "graphs.h"

/**
 * graph_create - allocates memory to store graph_t structure & initializes its
 *                content
 * Return: pointer to newly allocated graph structure
 */
graph_t *graph_create(void)
{
	graph_t *add = NULL;

	add = calloc(1, sizeof(graph_t));
	if (!add)
		return (NULL);
	add->nb_vertices = 0;
	add->vertices = NULL;
	return (add);
}
