#include "shelly.h"
/**
 * execs - exe cmd
 * @ment: string
 * @m: pointer1
 * @mm: pointer2
 * Return: exe cmd status
 */
int execs(char **ment, line_up **m, line_up **mm)
{
	struct stat r;
	int x, y;
	char g[10];

	if (cmdchk(ment, m))
		return (0);
	ment = line_confirm(&ment[0], *m, ment);
	y = asnchk(ment, mm);
	if ((y) != -1)
		return (0);
	confirm_refe(ment);
	ment = dolchk(ment, *mm);
	nwtrail(&ment[0], gttrail(ment[0]));
	if (stat(ment[0], &r) == 0)
	{
		if (fork() == 0)
			execve(ment[0], ment, environ);
		else
		{
			wait(&x);
			sprintf(g, "%d", x);
			plus_line_up(mm, "?", g);
		}
	}
	return (x);
}
