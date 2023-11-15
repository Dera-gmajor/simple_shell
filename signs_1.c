#include "shelly.h"
/**
 * double_and - same as &&
 * @list: pointer
 * @m: pointer2
 * @mm: pointer3
 */
void double_and(char *list, line_up *m, line_up *mm)
{
	char **g = NULL, **ment = NULL;
	int x;
	int y = 0;

	g = string_sep(list, "&&");
	for (x = 0; g[x] != NULL; x++)
	{
		if (y == 0)
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
 * sign_half_col - same as semicolon
 * @list: pointer1
 * @m: pointer
 * @mm: pointer
 */
void sign_half_col(char *list, line_up *m, line_up *mm)
{
	char **g = NULL, **ment = NULL;
	int x;

	g = string_sep(list, ";");
	for (x = 0; g[x] != NULL; x++)
	{
		ment = string_sep_2(g[x]);
		confirm_refe(ment);
		execs(ment, &m, &mm);
	}
	free(ment);
	free(g);
}
