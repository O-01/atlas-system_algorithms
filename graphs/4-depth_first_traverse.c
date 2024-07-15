#include "graphs.h"

void depth_visit(vertex_t *, size_t, size_t *, char *,
	void (*)(const vertex_t *, size_t));

/**
 * depth_first_traverse - traverse graph using depth-first algorithm
 * @graph: pointer to graph to be traversed
 * @action: pointer to function to be called at each visited vertex
 * Return: maximum vertex depth upon success, 0 upon failure
 */
size_t depth_first_traverse(const graph_t *graph,
	void (*action)(const vertex_t *v, size_t depth))
{
	char *visit = NULL;
	size_t deep = 0, max_deep = 0;

	if (!graph || (!graph->vertices || !graph->nb_vertices) || !action)
		return (0);
	visit = calloc(1, (graph->nb_vertices / 8) + 1);
	if (!visit)
		return (0);
	depth_visit(graph->vertices, deep, &max_deep, visit, action);
	free(visit), visit = NULL;
	return (max_deep);
}

/**
 * depth_visit - visit graph vertices prioritizing depth
 * @vrtx: pointer to current vertex being visited
 * @deep: current vertex depth
 * @max_deep: pointer to maximum vertex depth, to be increased with depth
 * @visit: pointer to bit array record of visited vertices
 * @action: pointer to function to be called at each visited vertex
 */
void depth_visit(vertex_t *vrtx, size_t deep, size_t *max_deep, char *visit,
	void (*action)(const vertex_t *v, size_t depth))
{
	edge_t *edge = NULL;

	action(vrtx, deep), visit[vrtx->index / 8] |= (1 << vrtx->index % 8);
	*max_deep = deep > *max_deep ? deep : *max_deep;
	if (!vrtx->edges)
		return;
	for (edge = vrtx->edges; edge; edge = edge->next)
		if (!(visit[edge->dest->index / 8] & (1 << edge->dest->index % 8)))
			depth_visit(edge->dest, deep + 1, max_deep, visit, action);
}
