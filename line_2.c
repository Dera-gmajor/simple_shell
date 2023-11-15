#include "shelly.h"
/**
 * fxn_print - prints list
 * @m: pointer
 */
void fxn_print(line_up *m)
{
	while (m != NULL)
	{
		dprintf(STDOUT_FILENO, "%s=%s\n", m->a, m->b);
		m = m->c;
	}
}

/**
 * line_release - frees a node
 * @m: pointer
 */
void line_release(line_up *m)
{
	line_up *w;

	while (m != NULL)
	{
		w = m;
		m = m->c;

		free(w->a);
		free(w->b);
		free(w);
	}
}
