#include "shelly.h"
/**
 * length - length
 * @g: pointer
 * @x: pointer2
 * Return: length
 */
int length(char *g, size_t *x)
{
	int n = 0;
	int y = 0;
	int z = 0;

	while (*x <= strlen(g))
	{
		if ((g[*x] == '\'' || g[*x] == '\"') && z == 0)
			z = 1;
		else if ((g[*x] == '\'' || g[*x] == '\"') && z == 1)
			z = 0;
		if ((g[*x] != ' ' && g[*x] != '\0') || z == 1)
		{
			n++;
			y = 1;
		}
		else if ((g[*x] == ' ' || g[*x] == '\0') && y == 1)
		{
			if (z == 0)
				return (n);
			y = 0;
		}
		*x += 1;
	}
	return (0);
}

/**
 * tabchk - checks space
 * @list: pointer
 * Return: pointer
 */
void tabchk(char **list)
{
	char *h = NULL;
	unsigned int j;
	unsigned int x;

	h = malloc(sizeof(char) * strlen(*list));
	strcpy(h, *list);

	for (x = 0; h[x] == ' '; x++)
	j = strlen(h) - x;
	*list = malloc(sizeof(char) * (j + 1));
	if (*list == NULL)
		return;

	strcpy(*list, &h[x]);
	free(h);
}

/**
 * wrdchk - checks word
 * @g: pointer
 * Return: number
 */
int wrdchk(char *g)
{
	size_t x = 0;
	size_t w = 0;
	size_t y = 0;
	size_t z = 0;

	for (x = 0; g[x] != '\0'; x++)
	{
		if ((g[x] == '\'' || g[x] == '\"') && z == 0)
			z = 1;
		else if ((g[x] == '\'' || g[x] == '\"') && z == 1)
			z = 0;
		if ((g[x] != ' ' && g[x] != '\0') && y == 0)
		{
			w++;
			y = 1;
		}
		else if ((g[x] == ' ' && z == 0) || x == strlen(g) - 1)
			y = 0;
	}
	return (w);
}
