#include "pathfinding.h"

#define BIG (1024 * 1024 * 4)
#define DIST_SUM(x) (current_dist + (x)->weight)
#define E_IDX(x) ((x)->dest->index)

static int prep(queue_t **, int **, int **, vertex_t ***, graph_t *);

/**
 * dijkstra_graph -
 * @graph:
 * @start:
 * @target:
 * Return:
 */
queue_t *dijkstra_graph(
	graph_t *graph, vertex_t const *start, vertex_t const *target)
{
	queue_t *q = NULL;
	vertex_t *current = NULL, **vertices = NULL;
	edge_t *edge = NULL;
	int *visit = NULL, *dist = NULL, current_dist = 0;
	size_t i = 0;

	if (!graph || !graph->vertices || !start || !target)
		return (NULL);
	if (!prep(&q, &visit, &dist, &vertices, graph))
		return (NULL);
	dist[start->index] = 0;
	for (; ;)
	{
		current_dist = BIG;
		for (current = NULL, i = 0; i < graph->nb_vertices; ++i)
			if (!visit[i] && dist[i] < BIG)
			{
				current = vertices[i], current_dist = dist[i];
				/* printf("current CONTENT: %s\n", current->content); */
				/* break; */
			}
		if (!current)
			break;
		printf("Checking %s, distance from %s is %d\n",
			current->content, start->content, current_dist);
		++visit[current->index];
		for (edge = current->edges; edge; edge = edge->next)
			if (!visit[E_IDX(edge)] && DIST_SUM(edge) < dist[E_IDX(edge)])
				/* printf("- Checking %s, distance from %s is %d\n",
					edge->dest->content, start->content, DIST_SUM(edge)), */
				dist[E_IDX(edge)] = DIST_SUM(edge);
	}
	if (!current)
		queue_delete(q), q = NULL;
	free(vertices), vertices = NULL;
	free(dist), dist = NULL;
	free(visit), visit = NULL;
	return (q);
}

static int prep(
	queue_t **q, int **visit, int **dist, vertex_t ***vertices, graph_t *graph)
{
	vertex_t *tmp = NULL;

	*q = queue_create();
	if (!*q)
		return (0);
	*visit = calloc(graph->nb_vertices, sizeof(int));
	if (!*visit)
		return (queue_delete(*q), 0);
	*dist = calloc(graph->nb_vertices, sizeof(int));
	if (!*dist)
		return (free(*visit), *visit = NULL, queue_delete(*q), 0);
	*vertices = calloc(graph->nb_vertices, sizeof(vertex_t *));
	if (!*vertices)
		return (free(*dist), *dist = NULL, free(*visit), *visit = NULL,
			queue_delete(*q), 0);
	for (tmp = graph->vertices; tmp; tmp = tmp->next)
		(*vertices)[tmp->index] = tmp, (*dist)[tmp->index] = BIG;
	return (1);
}
