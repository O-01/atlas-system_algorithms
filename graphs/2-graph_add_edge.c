#include "graphs.h"

static vertex_t *get_vertex(g_t *graph, const char *str);
static edge_t *get_add_point(edge_t *edges, const char *str, int *found);
static edge_t *create_edge(vertex_t *src, vertex_t *dest);

/**
 * graph_add_edge - adds edge between two vertices to existing graph
 * @graph: pointer to graph to which edge to be added
 * @src: string identifier for vertex for connection start
 * @dest: string identifier for vertex for connection termination
 * @type: type of edge, unidirectional or bidirectional
 * Return: 1 upon success, 0 upon failure
 */
int graph_add_edge(g_t *graph, const char *src, const char *dest, e_t_t type)
{
	vertex_t *src_vertex = NULL, *dest_vertex = NULL;
	edge_t *src_edge = NULL, *dest_edge = NULL;

	if (!graph || !src || !dest ||
		!strcmp(src, dest) || (!ISUNI(type) && !ISBI(type)))
		return (0);
	src_vertex = get_vertex(graph, src);
	dest_vertex = get_vertex(graph, dest);
	if (!src_vertex || !dest_vertex)
		return (0);
	src_edge = create_edge(src_vertex, dest_vertex);
	if (ISUNI(type))
		return (src_edge != NULL);
	dest_edge = create_edge(dest_vertex, src_vertex);
	if (!dest_edge)
	{
		free(src_edge), src_edge = NULL;
		--src_vertex->nb_edges;
		return (0);
	}
	return (src_edge && dest_edge);
}

/**
 * get_vertex - retrieves vertex from graph represented by str
 * @graph: graph within which search is performed
 * @str: key to locate vertex
 * Return: pointer to vertex if found, NULL otherwise
 */
static vertex_t *get_vertex(g_t *graph, const char *str)
{
	vertex_t *tmp_v = NULL;

	for (tmp_v = graph->vertices; tmp_v; tmp_v = tmp_v->next)
		if (!strncmp(tmp_v->content, str, strlen(str)))
			return (tmp_v);
	return (NULL);
}

/**
 * get_add_point - retrieves location on vertex for addition of new edge
 * @edges: list of edges related to source vertex
 * @str: string related to dest vertex to determine if edge already exists
 * @found: boolean set if desired edge already exists
 * Return: pointer to location to insert new edge upon success, NULL otherwise
 */
static edge_t *get_add_point(edge_t *edges, const char *str, int *found)
{
	edge_t *tmp = NULL;

	for (tmp = edges; tmp && tmp->next; tmp = tmp->next)
		if (!strncmp(tmp->dest->content, str, strlen(str)))
		{
			*found = 1;
			return (NULL);
		}
	return (tmp);
}

/**
 * create_edge - allocates memory & inserts edge at appropriate location
 * @src: vertex as connection start
 * @dest: vertex as connection termination
 * Return: pointer to newly created/inserted edge upon success, NULL otherwise
 */
static edge_t *create_edge(vertex_t *src, vertex_t *dest)
{
	edge_t *add = NULL, *add_point = NULL;
	int already_exists = 0;

	add_point = get_add_point(src->edges, dest->content, &already_exists);
	if (already_exists)
		return (NULL);
	add = calloc(1, sizeof(edge_t));
	if (!add)
		return (NULL);
	add->dest = dest;
	add->next = NULL;
	if (!add_point)
		src->edges = add;
	else
		add_point->next = add;
	++src->nb_edges;
	return (add);
}

/*
 * BELOW IS INITIAL DRAFT
 */

/* int */
/* graph_add_edge(g_t *graph, const char *src, const char *dest, e_t_t type) */
/* { */
	/* edge_t *add_src_e = NULL, *add_dest_e = NULL, *tmp_e = NULL; */
	/* vertex_t *tmp_v = NULL, *src_v = NULL, *dest_v = NULL; */
/*  */
	/* if (!graph || !src || !dest || */
		/* !strcmp(src, dest) || (!ISUNI(type) && !ISBI(type))) */
		/* return (0); */
	/* for (tmp_v = graph->vertices; tmp_v; tmp_v = tmp_v->next) */
	/* { */
		/* if (!strncmp(tmp_v->content, src, strlen(src))) */
			/* src_v = tmp_v; */
		/* else if (!strncmp(tmp_v->content, dest, strlen(dest))) */
			/* dest_v = tmp_v; */
	/* } */
	/* if (!src_v || !dest_v) */
		/* return (0); */
	/* for (tmp_e = src_v->edges; tmp_e && tmp_e->next; tmp_e = tmp_e->next) */
		/* if (!strncmp(tmp_e->dest->content, dest, strlen(dest))) */
			/* break; */
	/* add_src_e = calloc(1, sizeof(edge_t)); */
	/* if (!add_src_e) */
		/* return (0); */
	/* add_src_e->dest = dest_v; */
	/* add_src_e->next = NULL; */
	/* if (!tmp_e) */
		/* src_v->edges = add_src_e, ++src_v->nb_edges; */
	/* else */
		/* tmp_e->next = add_src_e; */
	/* if (ISUNI(type)) */
		/* return (1); */
	/* for (tmp_e = dest_v->edges; tmp_e && tmp_e->next; tmp_e = tmp_e->next) */
		/* if (!strncmp(tmp_e->dest->content, dest, strlen(dest))) */
			/* break; */
	/* add_dest_e = calloc(1, sizeof(edge_t)); */
	/* if (!add_dest_e) */
		/* return (0); */
	/* add_dest_e->dest = src_v; */
	/* add_dest_e->next = NULL; */
	/* if (!tmp_e) */
		/* dest_v->edges = add_dest_e, ++dest_v->nb_edges; */
	/* else */
		/* tmp_e->next = add_dest_e; */
	/* return (1); */
/* } */
