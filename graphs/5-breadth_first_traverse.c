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
	size_t deep = 0, this_depth = 1, at_depth = 0;
	char *visit = NULL;
	vertex_t *vrtx = NULL, **queue = NULL, **mark = NULL, **end = NULL;
	edge_t *edge = NULL;

	if (!graph || (!graph->vertices || !graph->nb_vertices) || !action)
		return (0);
	visit = calloc(1, (graph->nb_vertices / 8) + 1);
	if (!visit)
		return (0);
	queue = calloc(graph->nb_vertices, sizeof(vertex_t *));
	if (!queue)
	{
		free(visit), visit = NULL;
		return (0);
	}
	*queue = graph->vertices, mark = queue;
	visit[(*queue)->index / 8] |= (1 << (*queue)->index % 8);
	for (vrtx = *mark, end = queue + 1; vrtx; ++mark, vrtx = *mark)
	{
		action(vrtx, deep);
		for (edge = vrtx->edges; edge; edge = edge->next)
			if (!(visit[edge->dest->index / 8] & (1 << edge->dest->index % 8)))
				visit[edge->dest->index / 8] |= (1 << edge->dest->index % 8),
				*end = edge->dest, ++at_depth, ++end;
		if (!--this_depth && vrtx != *(end - 1))
			this_depth = at_depth, at_depth = 0, ++deep;
	}
	free(queue), queue = NULL;
	free(visit), visit = NULL;
	return (deep);
}
