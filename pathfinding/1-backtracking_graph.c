#include "pathfinding.h"

static queue_t *backtrack(
	vertex_t **visit, vertex_t *current, const vertex_t *target, queue_t *q);
static int is_visited(vertex_t **visit, vertex_t *current);

/**
 * backtracking_graph - searches for first path from starting point to target
 *                      point in graph
 * @graph: pointer to graph to go through
 * @start: pointer to starting vertex
 * @target: pointer to target vertex
 * Return: pointer to queue in which each node is char * corresponding to
 *         vertex, forming path from start to target
 */
queue_t *backtracking_graph(
	graph_t *graph, vertex_t const *start, vertex_t const *target)
{
	queue_t *q = NULL;
	vertex_t **visit = NULL;

	if (!graph || !graph->vertices || !start || !target)
		return (NULL);
	q = queue_create();
	if (!q)
		return (NULL);
	visit = calloc(graph->nb_vertices + 1, sizeof(vertex_t *));
	if (!visit)
		return (queue_delete(q), NULL);
	if (!backtrack(visit, (vertex_t *)&start->index, target, q))
		queue_delete(q), q = NULL;
	free(visit), visit = NULL;
	return (q);
}

/**
 * backtrack - backtrack through graph vertices recursively, adding to queue
 * @visit: group of vertices already visited
 * @current: vertex currently being processed
 * @target: vertex as expected end point on route
 * @q: queue to front of which vertex content added as applicable
 * Return: pointer to queue upon successful push to front, otherwise NULL
 */
static queue_t *backtrack(
	vertex_t **visit, vertex_t *current, const vertex_t *target, queue_t *q)
{
	static int visited;
	char *content = NULL;
	edge_t *edge = NULL;

	if (!current || (!current->edges && current != target) ||
		is_visited(visit, current))
		return (NULL);
	visit[visited++] = current;
	printf("Checking %s\n", current->content);
	for (edge = current->edges; edge; edge = edge->next)
		if (current == target || backtrack(visit, edge->dest, target, q))
		{
			content = calloc(1, strlen(current->content) + 1);
			if (!content)
				return (NULL);
			memcpy(content, current->content, strlen(current->content));
			queue_push_front(q, content);
			return (q);
		}
	return (NULL);
}

/**
 * is_visited - checks whether input vertex has already been visited
 * @visit: group of pointers to vertices already visited
 * @current: vertex to be verified against group of vertices already visited
 * Return: 1 if vertex has already been visited, otherwise 0
 */
static int is_visited(vertex_t **visit, vertex_t *current)
{
	vertex_t **vertex = NULL;

	for (vertex = visit; *vertex; ++vertex)
		if (*vertex == current)
			return (1);
	return (0);
}
