#include "shelly.h"
/**
 * gttrail - get path
 * @nm: ...
 * Return: NULL, otherwise path
 */
char *gttrail(char *nm)
{
	char *h = NULL;
	char *q = NULL;
	char *u = NULL;
	char *v = NULL;
	struct stat f;

	h = getenv("PATH");
	u = strdup(h);
	q = strtok(u, ":");

	if (stat(nm, &f) != 0)
	{
		while (q)
		{
			v = malloc((sizeof(char) * (strlen(q) + (strlen(nm)) + 2)));
				if (v == NULL)
				exit(EXIT_FAILURE);
				strcpy(v, q);
				strcat(v, "/");
				strcat(v, nm);
				if (stat(v, &f) == 0)
				{
					free(u);
					return (v);
				}
				free(v);
				q = strtok(NULL, ":");
		}
	}
	free(u);
	free(q);
	return (NULL);
}

/**
 * nwtrail - path getting
 * @nm: ...
 * @v: ..
 */
void nwtrail(char **nm, char *v)
{
	if (v != NULL)
	{
		*nm = realloc(*nm, (sizeof(char) * strlen(v)));
		if (*nm == NULL)
			return;
		*nm = v;
	}
}
