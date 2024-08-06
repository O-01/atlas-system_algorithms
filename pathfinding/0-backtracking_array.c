#include "pathfinding.h"

static queue_t *backtrack(char **map, char **visit, int x, int y, q_t *q);

int limit[4];

/**
 * backtracking_array - searches for first path from start point to target
 *                      point within two-dimensional array
 * @map: pointer to read-only two-dimensional array
 *       0 represents walkable cell
 *       1 represents blocked cell
 * @rows: number of rows within map
 * @cols: number of columns within map
 * @start: pointer to struct containing coordinates of start point
 * @target: pointer to struct containing coordinates of end point
 * Return: pointer to queue containing path from start to target upon success,
 *         otherwise NULL upon error or no path exists
 */
queue_t *backtracking_array(
	char **map, int rows, int cols, point_t const *start, point_t const *target)
{
	q_t *q = NULL;
	char **visit = NULL;
	int row = 0;

	if (!map || !*map || !rows || !cols || !start || !target)
		return (NULL);
	limit[Y] = rows - 1, limit[X] = cols - 1;
	limit[TARGET_Y] = target->y, limit[TARGET_X] = target->x;
	q = queue_create();
	if (!q)
		return (NULL);
	visit = calloc(1, rows * sizeof(char *));
	if (!visit)
		return (queue_delete(q), NULL);
	for (; row < rows; ++row)
		visit[row] = calloc(1, (cols / 8) + 1);
	if (!backtrack(map, visit, start->x, start->y, q))
		queue_delete(q), q = NULL;
/*
 *	for (int y = 0; y < rows - 1; ++y)
 *		for (int x = 0; x < cols - 1; ++x)
 *			printf("%c%s",
 *				visit[y][x / 8] & (1 << (x % 8)) ? '1' : '0',
 *				x + 1 < cols - 1 ? "" : "\n");
 */
	for (row = 0; row < rows; ++row)
		free(visit[row]), visit[row] = NULL;
	free(visit), visit = NULL;
	return (q);
}

/**
 * backtrack - backtrack within map recursively, adding to queue
 * @map: array of char arrays representing navigable area
 * @visit: array of bit arrays corresponding to visited elements of map
 * @x: x-axis/column coordinate of current element
 * @y: y-axis/row coordinate of current element
 * @q: queue to front of which new point to be added as necessary
 * Return: pointer to queue upon successful push to front, otherwise NULL
 */
static queue_t *backtrack(char **map, char **visit, int x, int y, q_t *q)
{
	point_t *add = NULL;

	if ((y < 0 || y > limit[Y]) || (x < 0 || x > limit[X]) ||
		(map[y][x] == '1') || (visit[y][x / 8] & (1 << (x % 8))))
		return (NULL);
	visit[y][x / 8] |= (1 << (x % 8));
	printf("Checking coordinates [%d, %d]\n", x, y);
	if ((x == limit[TARGET_X] && y == limit[TARGET_Y]) ||
		backtrack(map, visit, x + 1, y, q) || backtrack(map, visit, x, y + 1, q) ||
		backtrack(map, visit, x - 1, y, q) || backtrack(map, visit, x, y - 1, q))
	{
		add = calloc(1, sizeof(point_t));
		if (!add)
			return (NULL);
		add->x = x, add->y = y;
		queue_push_front(q, add);
		return (q);
	}
	return (NULL);
}
