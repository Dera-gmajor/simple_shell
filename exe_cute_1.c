#include "shelly.h"
/**
 * lineexecs - execute line
 * @list: line
 * @m: pointer
 * @mm: pointer2
 * Return: NULL, otherwise string pointer
 */
char **lineexecs(char *list, line_up **m, line_up **mm)
{
	int p = 0, x;
	char **ment = NULL;
	int y;

	x = strlen(list);

	if (list[x - 1] == '\n')
		list[x - 1] = '\0';
	cmtchk(&list);

	p = sepchk(list, *m, *mm);
	if (p == -1)
	{
		ment = string_sep_2(list);
		y = execs(ment, m, mm);
		if (y != 0)
			return (ment);
	}
	return (NULL);
}
