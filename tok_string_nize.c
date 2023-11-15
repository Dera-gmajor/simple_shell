#include "shelly.h"
/**
 * nizestrings - string tok
 * @g: double pointer
 * @e: string
 * Return: NULL, otherwise token
 */
char *nizestrings(char **g, char *e)
{
	char *f, *k;
	int ns = strlen(e);
	char *j = *g;

	if (*g == NULL || strcmp(*g, "\0") == 0)
		return (NULL);
	while (strncmp(*g, e, 1) == 0)
	{
		*g = strndup(&j[1], (strlen(*g) - 1));
		j = *g;
	}
	f = strstr(*g, e);
	if (f == NULL)
	{
		k = *g;
		*g = NULL;
		return (k);
	}
	k = strndup(*g, (strlen(*g) - strlen(f)));
	*g = strndup(&f[ns], strlen(f) - ns);

	if (strcmp(k, " ") == 0)
		return (NULL);
	return (k);
}

/**
 * listergt - list
 * @f: pointer
 * @y: size
 * Return: numver
 */
int listergt(char **f, size_t y)
{
	int z;

	*f = malloc(sizeof(char) * y);
	if (*f == NULL)
		exit(EXIT_FAILURE);
	z = read(STDIN_FILENO, *f, y);
	if (z == 0)
		return (-1);
	else
		return (z);
	return (1);
}
