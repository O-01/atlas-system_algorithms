#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include <stdio.h>
#include <stdlib.h>

#include "queues.h"
#include "graphs.h"

typedef queue_t q_t;

/**
 * struct point_s - Structure storing coordinates
 * @x: X coordinate
 * @y: Y coordinate
 */
typedef struct point_s
{
	int x;
	int y;
} point_t;

typedef point_t p_t;

queue_t *backtracking_array(
	char **map, int rows, int cols, p_t const *start, p_t const *target);
queue_t *backtracking_graph(
	graph_t *graph, vertex_t const *start, vertex_t const *target);
queue_t *dijkstra_graph(
	graph_t *graph, vertex_t const *start, vertex_t const *target);

/* ADVANCED */
queue_t *a_star_graph(
	graph_t *graph, vertex_t const *start, vertex_t const *target);

#endif