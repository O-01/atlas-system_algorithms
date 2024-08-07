#include "pathfinding.h"

static queue_t *backtrack(
	vertex_t **visit, vertex_t *current, const vertex_t *target, queue_t *q);
static int is_visited(vertex_t **visit, vertex_t *current);

static int visited;

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

	if (!graph || !graph->vertices || !start || !target)
		return (NULL);
	q = queue_create();
	if (!q)
		return (NULL);
	visit = calloc(graph->nb_vertices + 1, sizeof(vertex_t *));
	if (!visit)
		return(queue_delete(q), NULL);
	if (!backtrack(visit, (vertex_t *)&start->index, target, q))
		queue_delete(q), puts("0--------------------------\n"), q = NULL;
	free(visit), visit = NULL;
	return (q);
}

static queue_t *backtrack(
	vertex_t **visit, vertex_t *current, const vertex_t *target, queue_t *q)
{
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

static int is_visited(vertex_t **visit, vertex_t *current)
{
	vertex_t **vertex = NULL;

	for (vertex = visit; *vertex; ++vertex)
		if (*vertex == current)
			return (1);
	return (0);
}
