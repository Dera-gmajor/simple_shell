#include "shelly.h"
/**
 * a_k_a - alias list adding
 * @ment: Double pointer
 * @m: Pointer
 */
void a_k_a(char **ment, line_up **m)
{
	char **g = NULL;
	int x = 1, z;
	int y = 0;
	line_up *t;

	if (ment[1] == NULL)
		fxn_print(*m);

	while (ment[x] != NULL)
	{
		z = tiebreaker(*m, ment[x]);
		if (strchr(ment[x], '='))
		{
			g = string_sep(ment[x], "=");
			plus_line_up(m, g[0], g[1]);
		}
		else if (z != -1)
		{
			t = *m;
			while (y < z)
			{
				t = t->c;
				y++;
			}
			dprintf(STDOUT_FILENO, "%s=%s \n", t->a, t->b);
		}
		else
			perror(ment[x]);
		x++;
	}
}

/**
 * quit - leave the shell
 * @ment: Double pointer
 * @m: Pointer
 */
void quit(char **ment, __attribute__((unused)) line_up **m)
{
	if (ment[1] == NULL)
		exit(EXIT_SUCCESS);
	exit(atoi(ment[1]));
}
