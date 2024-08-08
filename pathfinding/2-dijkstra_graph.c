#include "pathfinding.h"

#define BIG (1024 * 1024 * 4)
#define DIST_SUM(x) (current_dist + (x)->weight)
#define E_IDX(x) ((x)->dest->index)

static int prep(q_t **, int **, int **, vertex_t ***, vertex_t ***, graph_t *);
static int get_path(queue_t **, const vertex_t *, vertex_t *, vertex_t **);
static void free_stuff(vertex_t **, vertex_t **, int *, int *);

/**
 * dijkstra_graph - searches for shortest path from starting point to target
 *                  point in graph
 * @graph: pointer to graph to go through
 * @start: pointer to starting vertex
 * @target: pointer to target vertex
 * Return: queue data structure containing points representing shortest path
 *         from starting point to target point upon success, otherwise NULL
 *         pointer
 */
queue_t *dijkstra_graph(
	graph_t *graph, vertex_t const *start, vertex_t const *target)
{
	queue_t *q = NULL;
	int *visit = NULL, *dist = NULL, current_dist = 0;
	vertex_t **vertices = NULL, **route = NULL, *current = NULL;
	size_t iter = 0;
	edge_t *edge = NULL;

	if (!graph || !graph->vertices || !start || !target)
		return (NULL);
	if (!prep(&q, &visit, &dist, &vertices, &route, graph))
		return (NULL);
	dist[start->index] = 0;
	route[start->index] = (vertex_t *)&start->index;
	for (current_dist = BIG; current != target; current_dist = BIG)
	{
		for (current = NULL, iter = 0; iter < graph->nb_vertices; ++iter)
			if (!visit[iter] && dist[iter] < current_dist)
				current = vertices[iter], current_dist = dist[current->index];
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

/**
 * prep - allocates memory for data structures to be used in dijkstra_graph
 * @q: queue data structure, record of shortest path from A to B
 * @visit: pointer to integer array, record of visited/processed vertices
 * @dist: pointer to integer array, record of distances from start point
 * @vertices: pointer to array of pointers to vertices, serialization of all
 *            vertices within graph ordered by index
 * @route: pointer to array of pointers to vertices, serialization of vertices
 *         composing route from start to target, as applicable
 * @graph: pointer to graph to go through
 * Return: 1 upon total success, otherwise 0 upon error
 */
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

/**
 * get_path - enqueue content sequentially from points on route composing
 *            shortest path from A to B
 * @q: queue data structure, record of shortest path from A to B
 * @start: pointer to starting vertex
 * @current: pointer to vertex, assumed to be pointer to target vertex
 * @route: pointer to array of pointers to vertices, serialization of vertices
 *         composing route from start to target, as applicable
 * Return: 1 upon success, otherwise 0 upon error
 */
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

/**
 * free_stuff - frees memory allocated within dijkstra_graph
 * @route: pointer to array of pointers to vertices, serialization of vertices
 *         composing route from start to target, as applicable
 * @vertices: pointer to array of pointers to vertices, serialization of all
 *            vertices within graph ordered by index
 * @dist: pointer to integer array, record of distances from start point
 * @visit: pointer to integer array, record of visited/processed vertices
 */
static void free_stuff(
	vertex_t **route, vertex_t **vertices, int *dist, int *visit)
{
	free(route), route = NULL;
	free(vertices), vertices = NULL;
	free(dist), dist = NULL;
	free(visit), visit = NULL;
}
