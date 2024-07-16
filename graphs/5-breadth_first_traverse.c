#include "graphs.h"

/**
 * breadth_first_traverse - traverse graph using breadth-first algorithm
 * @graph: pointer to graph to be traversed
 * @action: pointer to function to be called at each visited vertex
 * Return: maximum vertex depth upon success, 0 upon failure
 */
size_t breadth_first_traverse(const graph_t *graph,
	void (*action)(const vertex_t *v, size_t depth))
{
	char *visit = NULL;
	vertex_t *vrtx = NULL, **queue = NULL, **mark = NULL, **end = NULL;
	edge_t *edge = NULL;
	size_t deep = 0, *level = NULL;

	if (!graph || (!graph->vertices || !graph->nb_vertices) || !action)
		return (0);
	visit = calloc(1, (graph->nb_vertices / 8) + 1);
	if (!visit)
		return (0);
	queue = calloc(graph->nb_vertices + 1, sizeof(vertex_t *));
	if (!queue)
		return ((free(visit), visit = NULL), 0);
	level = calloc(graph->nb_vertices, sizeof(size_t));
	if (!level)
		return ((free(queue), queue = NULL, free(visit), visit = NULL), 0);
	*queue = graph->vertices, mark = queue;
	visit[(*queue)->index / 8] |= (1 << (*queue)->index % 8);
	for (vrtx = *mark, end = queue + 1; vrtx; ++mark, vrtx = *mark)
	{
		action(vrtx, level[vrtx->index]);
		for (edge = vrtx->edges; edge; edge = edge->next)
			if (!(visit[edge->dest->index / 8] & (1 << edge->dest->index % 8)))
				*end = edge->dest, ++end,
				level[edge->dest->index] = level[vrtx->index] + 1,
				visit[edge->dest->index / 8] |= (1 << edge->dest->index % 8);
	}
	deep = level[(*(end - 1))->index];
	free(level), level = NULL;
	free(queue), queue = NULL;
	free(visit), visit = NULL;
	return (deep);
}
