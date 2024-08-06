#include "pathfinding.h"

queue_t *btrack(char **map, char **visit, int x, int y, q_t *q);

int limit[4];

/**
 * backtracking_array -
 * @map:
 * @rows:
 * @cols:
 * @start:
 * @end:
 * Return:
 */
queue_t *backtracking_array(
	char **map, int rows, int cols, point_t const *start, point_t const *end)
{
	q_t *q = NULL;
	char **visit = NULL;
	int row = 0;

	if (!map || !*map || !rows || !cols || !start || !end)
		return (NULL);
	limit[Y] = rows - 1, limit[X] = cols - 1;
	limit[TARGET_Y] = end->y, limit[TARGET_X] = end->x;
	q = queue_create();
	if (!q)
		return (NULL);
	visit = calloc(1, rows * sizeof(char *));
	if (!visit)
		return (queue_delete(q), NULL);
	for (; row < rows; ++row)
		visit[row] = calloc(1, (cols / 8) + 1);
	if (!btrack(map, visit, start->x, start->y, q))
		return (queue_delete(q), NULL);
	/* for (int y = 0; y < rows - 1; ++y)
		for (int x = 0; x < cols - 1; ++x)
			printf("%c%s",
				visit[y][x / 8] & (1 << x % 8) ? '1' : '0',
				x + 1 < cols - 1 ? "" : "\n"); */
	for (row = 0; row < rows; ++row)
		free(visit[row]), visit[row] = NULL;
	free(visit), visit = NULL;
	return (q);
}

queue_t *btrack(char **map, char **visit, int x, int y, q_t *q)
{
	point_t *add = NULL;

	if ((y < 0 || y > limit[Y]) || (x < 0 || x > limit[X]) ||
		(map[y][x] == '1') || (visit[y][x / 8] & (1 << (x % 8))))
		return (NULL);
	visit[y][x / 8] |= (1 << (x % 8));
	printf("Checking coordinates [%d, %d]\n", x, y);
	if ((x == limit[TARGET_X] && y == limit[TARGET_Y]) ||
		btrack(map, visit, x + 1, y, q) || btrack(map, visit, x, y + 1, q) ||
		btrack(map, visit, x - 1, y, q) || btrack(map, visit, x, y - 1, q))
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
