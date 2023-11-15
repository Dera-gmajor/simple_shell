#include "shelly.h"
/**
 * string_sep - strings sep
 * @list: pointer
 *
 * @e: pointer
 * Return: array
 */
char **string_sep(char *list, char *e)
{
	char *k = NULL, *w = NULL;
	char **g = NULL;
	int x = 0;
	int lists = 0;

	tabchk(&list);
	w = strdup(list);
	k = nizestrings(&w, e);

	while (k != NULL)
	{
		lists++;
		k = nizestrings(&w, e);
	}
	g = malloc(sizeof(char *) * (lists + 1));
	if (g == NULL)
		exit(EXIT_FAILURE);
	k = nizestrings(&list, e);
	while (k != NULL)
	{
		g[x] = malloc(sizeof(char) * strlen(k));
		if (g[x] == NULL)
		{
			for (x = 0; x < lists; x++)
				free(g[x]);
			free(g);
			exit(EXIT_FAILURE);
		}
		g[x] = k;
		k = nizestrings(&list, e);
		x++;
	}
	g[x] = NULL;
	free(k);
	free(w);
	return (g);
}

/**
 * string_sep_2 - sep str
 * @list: pointer
 * Return: array
 */
char **string_sep_2(char *list)
{
	char **g = NULL;
	int x, n, w = 0;
	size_t *y, d;

	tabchk(&list);
	w = wrdchk(list);
	g = malloc(sizeof(char *) * (w + 1));
	if (g == NULL)
		return (NULL);
	d = 0;
	for (x = 0; x < w; x++)
	{
		y = &d;
		n = length(list, y);
		g[x] = malloc(sizeof(char) * (n + 1));
		if (g[x] == NULL)
		{
			for (x = 0; x <= w; x++)
				free(g[x]);
			free(g);
			return (NULL);
		}
		g[x] = strndup(&list[*y - n], n);
	}
	g[x] = NULL;
	return (g);
}
