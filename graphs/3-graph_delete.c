#include "graphs.h"

static void edges_delete(vertex_t *vertex);

/**
 * graph_delete - completely deletes graph
 * @graph: graph to be deleted
 */
void graph_delete(graph_t *graph)
{
	vertex_t *tmp = NULL, *current = NULL;

	if (!graph)
		return;
	for (current = graph->vertices; current; current = tmp)
	{
		tmp = current->next;
		edges_delete(current);
		free(current->content), current->content = NULL;
		free(current), current = NULL;
		--graph->nb_vertices;
	}
	free(graph), graph = NULL;
}

/**
 * edges_delete - deletes all edges related to input vertex
 * @vertex: vertex, all edges of which are to be deleted
 */
static void edges_delete(vertex_t *vertex)
{
	edge_t *tmp = NULL, *current = NULL;

	if (!vertex || !vertex->edges)
		return;
	for (current = vertex->edges; current; current = tmp)
	{
		tmp = current->next;
		free(current), current = NULL;
		--vertex->nb_edges;
	}
}
