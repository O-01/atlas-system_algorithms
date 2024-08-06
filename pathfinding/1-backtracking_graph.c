#include "pathfinding.h"

queue_t *backtrack(graph_t *graph, vertex_t *current, vertex_t *target);

/**
 * backtracking_graph -
 * @
 * Return:
 */
queue_t *backtracking_graph(
	graph_t *graph, vertex_t const *start, vertex_t const *target)
{
	queue_t *q = NULL;
	vertex_t **visit = NULL;

	if (!graph || graph->vertices || !start || !target)
		return (NULL);
	q = queue_create();
	if (!q)
		return (NULL);
	visit = calloc(1, graph->nb_vertices * sizeof(vertex_t *));
	if (!visit)
		return (queue_delete(q), NULL);
	;
}
