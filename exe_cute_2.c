#include "shelly.h"
/**
 * cmdchk - checks cmd
 * @ment: argument
 * @m: pointer
 * Return: 0 if fails, otherwise 1
 */
int cmdchk(char **ment, line_up **m)
{
	int x = 0;

	cmd cmd[] = {
		{"unsetenv", environ_unset}, {"alias", a_k_a},
		{"setenv", environ_set}, {"exit", quit},
		{"cd", root_check}, {NULL, NULL}
	};

	while (cmd[x].am != NULL)
	{
		ment[0] = confirm_ref(ment[0]);
		if (strcmp(ment[0], cmd[x].am) == 0)
		{
			cmd[x].fxn(ment, m);
			return (1);
		}
		x++;
	}
	return (0);
}

/**
 * asnchk - asdigns
 * @ment: array
 * @m: double pointer
 * Return: 0 if sucess, otherwise -1
 */
int asnchk(char **ment, line_up **m)
{
	int x;
	char **g = NULL;

	for (x = 0; ment[x] != NULL; x++)
	{
		if (strchr(ment[x], '='))
		{
			g = string_sep(ment[x], "=");
			plus_line_up(m, g[0], g[1]);
		}
		else
		{
			return (-1);
		}
	}
	return (0);
}

/**
 * cmtchk - check existed cmt
 * @list: double pointer
 */
void cmtchk(char **list)
{
	char *g = strchr(*list, '#');

	if (g != NULL)
		*list = strndup(*list, strlen(*list) - strlen(g));
}
