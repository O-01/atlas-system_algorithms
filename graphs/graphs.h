#ifndef _GRAPHS_H_
#define _GRAPHS_H_

#include <stdio.h>
#include <stdlib.h>

#ifndef __USE_XOPEN2K8
#define __USE_XOPEN2K8
#endif
#include <string.h>

/**
 * enum edge_type_e - Enumerates the different types of
 * connection between two vertices
 *
 * @UNIDIRECTIONAL: The connection is made only in one way
 * @BIDIRECTIONAL: The connection is made in two ways
 */
typedef enum edge_type_e
{
	UNIDIRECTIONAL = 0,
	BIDIRECTIONAL
} edge_type_t;

#define UNI UNIDIRECTIONAL
#define ISUNI(x) ((x) == UNI)

#define BI BIDIRECTIONAL
#define ISBI(x) ((x) == BI)

/* Define the structure temporarily for usage in the edge_t */
typedef struct vertex_s vertex_t;

/**
 * struct edge_s - Node in the linked list of edges for a given vertex
 * A single vertex can have many edges
 *
 * @dest: Pointer to the connected vertex
 * @next: Pointer to the next edge
 */
typedef struct edge_s
{
	vertex_t	*dest;
	struct edge_s   *next;
} edge_t;


/**
 * struct vertex_s - Node in the linked list of vertices in the adjacency list
 *
 * @index: Index of the vertex in the adjacency list.
 * @content: Custom data stored in the vertex (here, a string)
 * @nb_edges: Number of conenctions with other vertices in the graph
 * @edges: Pointer to the head node of the linked list of edges
 * @next: Pointer to the next vertex in the adjacency linked list
 *   This pointer points to another vertex in the graph, but it
 *   doesn't stand for an edge between the two vertices
 */
struct vertex_s
{
	size_t	  index;
	char		*content;
	size_t	  nb_edges;
	edge_t	  *edges;
	struct vertex_s *next;
};

/**
 * struct graph_s - Representation of a graph
 * We use an adjacency linked list to represent our graph
 *
 * @nb_vertices: Number of vertices in our graph
 * @vertices: Pointer to the head node of our adjacency linked list
 */
typedef struct graph_s
{
	size_t	  nb_vertices;
	vertex_t	*vertices;
} graph_t;

/* FOR BETTY FORMATTING REQUIREMENTS */
typedef edge_type_t e_t_t;
typedef vertex_t v_t;
typedef graph_t g_t;

void graph_display(const graph_t *graph);

g_t *graph_create(void);
vertex_t *graph_add_vertex(g_t *, const char *);
int graph_add_edge(g_t *, const char *, const char *, e_t_t);
void graph_delete(g_t *);
size_t depth_first_traverse(const g_t *, void (*)(const v_t *, size_t));
size_t breadth_first_traverse(const g_t *, void (*)(const v_t *, size_t));

#endif /* _GRAPHS_H_ */
