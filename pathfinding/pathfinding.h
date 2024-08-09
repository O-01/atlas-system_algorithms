#ifndef _PATHFINDING_H_
#define _PATHFINDING_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queues.h"
#include "graphs.h"

#define BIG (0x7FFFFFFF)
#define FREE_0(x) (free((x)), (x) = NULL)

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

/**
 * enum coordinates_arr_e - enum for coordinates within two-dimensional array
 * @Y: y-axis/row coordinate
 * @X: x-axis/column coordinate
 * @TARGET_Y: target y-axis/row coordinate
 * @TARGET_X: target x-axis/column coordinate
 */
typedef enum coordinates_arr_e
{
	Y = 0,
	X,
	TARGET_Y,
	TARGET_X
} coord_arr;

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
