#include "graphs.h"

/**
 * graph_add_vertex - adds vertex to existing graph
 * @graph: pointer to graph to which to be added vertex
 * @str: string to be stored in new vertex
 * Return: pointer to created vertex upon success, otherwise NULL
 */
vertex_t *graph_add_vertex(graph_t *graph, const char *str)
{
	vertex_t *add_v = NULL, *tmp = NULL, *last = tmp;

	if (!graph || !str)
		return (NULL);
	for (tmp = graph->vertices; tmp; last = tmp, tmp = tmp->next)
		if (!strncmp(tmp->content, str, strlen(str)))
			return (NULL);
	add_v = calloc(1, sizeof(vertex_t));
	if (!add_v)
		return (NULL);
	add_v->index = ++graph->nb_vertices - 1;
	add_v->content = strndup(str, strlen(str));
	if (!add_v->content)
	{
		free(add_v), add_v = NULL;
		return (NULL);
	}
	add_v->nb_edges = 0;
	add_v->edges = NULL;
	add_v->next = NULL;
	if (!graph->vertices && !last)
	{
		graph->vertices = add_v;
		return (add_v);
	}
	last->next = add_v;
	return (add_v);
}

/*
 * BELOW IS INITIAL DRAFT - allocation is performed before vertices list
 *                          evaluated for possible pre-existing value, memory
 *                          freed if matching value detected during insertion
 */

/* vertex_t *graph_add_vertex(graph_t *graph, const char *str) */
/* { */
	/* vertex_t *add_v = NULL, *tmp = NULL; */
/*  */
	/* if (!graph || !str) */
		/* return (NULL); */
	/* add_v = calloc(1, sizeof(vertex_t)); */
	/* if (!add_v) */
		/* return (NULL); */
	/* add_v->index = ++graph->nb_vertices - 1; */
	/* add_v->content = strdup(str); */
	/* add_v->nb_edges = 0; */
	/* add_v->edges = NULL; */
	/* add_v->next = NULL; */
	/* if (!graph->vertices) */
	/* { */
		/* graph->vertices = add_v; */
		/* return (add_v); */
	/* } */
	/* for (tmp = graph->vertices; tmp && tmp->next; tmp = tmp->next) */
		/* if (!strncmp(tmp->content, str, strlen(str))) */
		/* { */
			/* --graph->nb_vertices; */
			/* free(add_v->content), add_v->content = NULL; */
			/* free(add_v), add_v = NULL; */
			/* return (NULL); */
		/* } */
	/* tmp->next = add_v; */
	/* return (add_v); */
/* } */
