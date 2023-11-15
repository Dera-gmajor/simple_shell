#include "shelly.h"
/**
 * plus_line_up - adds node
 * @m: pointer
 * @a: ...
 * @b: ...
 */
void plus_line_up(line_up **m, char *a, char *b)
{
	line_up *n, *t;
	int x = 0;
	int y;

	n = malloc(sizeof(line_up));
	if (n == NULL)
		return;
	x = tiebreaker(*m, a);

	if (x == -1)
	{
		n->a = strdup(a);
		n->b = strdup(b);
		n->c = NULL;

		t = *m;
		if (*m == NULL)
			*m = n;

		else
		{
			while (t->c != NULL)
				t = t->c;
			t->c = n;
		}
	}
	else
	{
		t = *m;
		y = 0;

		while (y < x)
		{
			t = t->c;
			y++;
		}
		t->b = strdup(b);
	}
}

/**
 * line_confirm - alias list
 * @nm: double pointer
 * @m: pointer
 * @ment: array
 * Return: array
 */
char **line_confirm(char **nm, line_up *m, char **ment)
{
	line_up *t = m;

	while (t != NULL)
	{
		if (strcmp(t->a, *nm) == 0)
		{
			*nm = strdup(t->b);
			confirm_ref(*nm);
			ment = string_sep(*nm, " ");
			return (ment);
		}
		t = t->c;
	}
	return (ment);
}

/**
 * tiebreaker - check for alias
 * @m: pointer
 * @a: pointer
 * Return: index, otherwise -1
 */
int tiebreaker(line_up *m, char *a)
{
	line_up *t = m;
	int x = 0;

	while (t != NULL)
	{
		if (strcmp(t->a, a) == 0)
			return (x);
		t = t->c;
		x++;
	}
	return (-1);
}
