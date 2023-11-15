#include "shelly.h"
/**
 * dolgt - ..
 * @m: pointer
 * @nm: double pointer
 * Return: pointer
 */
char *dolgt(line_up *m, char **nm)
{
	line_up *t = m;
	char *k = *nm;
	pid_t pd;

	k = strndup(&k[1], (strlen(*nm) - 1));
	if (getenv(k))
	{
		*nm = strdup(getenv(k));
		return (*nm);
	}
	else if (strcmp(k, "$") == 0)
	{
		pd = getpid();
		sprintf(*nm, "%d", pd);
		return (*nm);
	}
	while (t != NULL)
	{
		if (strcmp(t->a, k) == 0)
		{
			*nm = strdup(t->b);
			confirm_refe(nm);
			free(k);
			return (*nm);
		}
		t = t->c;
	}
	free(k);
	return (*nm);
}
