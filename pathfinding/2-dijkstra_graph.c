#include "pathfinding.h"

#define BIG (1024 * 1024 * 4)
#define DIST_SUM(x) (current_dist + (x)->weight)
#define E_IDX(x) ((x)->dest->index)

static int prep(q_t **, int **, int **, vertex_t ***, vertex_t ***, graph_t *);
static int get_path(queue_t **, const vertex_t *, vertex_t *, vertex_t **);
static void free_stuff(vertex_t **, vertex_t **, int *, int *);

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
	vertex_t *current = NULL, **vertices = NULL, **route = NULL;
	edge_t *edge = NULL;
	int *visit = NULL, *dist = NULL, current_dist = 0;
	size_t i = 0;

	if (!graph || !graph->vertices || !start || !target)
		return (NULL);
	if (!prep(&q, &visit, &dist, &vertices, &route, graph))
		return (NULL);
	dist[start->index] = 0;
	route[start->index] = (vertex_t *)&start->index;
	for (; current != target;)
	{
		current_dist = BIG;
		for (current = NULL, i = 0; i < graph->nb_vertices; ++i)
			if (!visit[i] && dist[i] < current_dist)
				current = vertices[i], current_dist = dist[current->index];
		if (!current)
			break;
		printf("Checking %s, distance from %s is %d\n",
			current->content, start->content, current_dist);
		++visit[current->index];
		for (edge = current->edges; edge; edge = edge->next)
			if (!visit[E_IDX(edge)] && DIST_SUM(edge) < dist[E_IDX(edge)])
				dist[E_IDX(edge)] = DIST_SUM(edge),
				route[E_IDX(edge)] = current;
	}
	if (!current || current != target || !get_path(&q, start, current, route))
		queue_delete(q), q = NULL;
	free_stuff(route, vertices, dist, visit);
	return (q);
}

static int prep(queue_t **q, int **visit, int **dist,
	vertex_t ***vertices, vertex_t ***route, graph_t *graph)
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
	*route = calloc(graph->nb_vertices, sizeof(vertex_t *));
	if (!route)
		return (free(*vertices), *vertices = NULL, free(*dist), *dist = NULL,
			free(*visit), *visit = NULL, queue_delete(*q), 0);
	return (1);
}

static int get_path(
	queue_t **q, const vertex_t *start, vertex_t *current, vertex_t **route)
{
	char *content = NULL;

	for (; current != start; current = route[current->index])
	{
		content = calloc(1, strlen(current->content) + 1);
		if (!content)
			return (0);
		memcpy(content, current->content, strlen(current->content));
		queue_push_front(*q, content);
	}
	content = calloc(1, strlen(start->content) + 1);
	if (!content)
		return (0);
	memcpy(content, start->content, strlen(start->content));
	queue_push_front(*q, content);
	return (1);
}

static void free_stuff(
	vertex_t **route, vertex_t **vertices, int *dist, int *visit)
{
	free(route), route = NULL;
	free(vertices), vertices = NULL;
	free(dist), dist = NULL;
	free(visit), visit = NULL;
}
