#include "shelly.h"
/**
 * double_or - sams as or
 * @list: pointer
 * @m: pointer2
 * @mm: pointer3
 */
void double_or(char *list, line_up *m, line_up *mm)
{
	char **g = NULL, **ment = NULL;
	int x;
	int y = 0;

	g = string_sep(list, "||");
	for (x = 0; g[x] != NULL; x++)
	{
		if (y != 0)
		{
			ment = string_sep_2(g[x]);
			confirm_refe(ment);
			y = execs(ment, &m, &mm);
		}
	}
	free(ment);
	free(g);
}

/**
 * sepchk - checks sep
 * @list: pointer
 * @m: pointer
 * @mm: pointer
 * Return: -1 if fail, otherwise 1
 */
int sepchk(char *list, line_up *m, line_up *mm)
{
	int y;
	int x;

	sys sy[] = {
		{'|', double_or}, {'&', double_and},
		{';', sign_half_col}, {'\0', NULL}};

	for (y = 0; sy[y].c != '\0'; y++)
	{
		for (x = 0; list[x] != '\0'; x++)
		{
			if (list[x] == sy[y].c)
			{
				sy[y].fxn(list, m, mm);
				return (1);
			}
		}
	}
	return (-1);
}
