#include "shelly.h"
/**
 * dolchk - checks
 * @ment: array
 * @m: pointer
 * Return: array
 */
char **dolchk(char **ment, line_up *m)
{
	int x = 0;

	while (ment[x] != NULL)
	{
		if (strchr(ment[x], '$'))
			ment[x] = dolgt(m, &ment[x]);
		x++;
	}
	return (ment);
}

/**
 * prompt_display - displays prompt
 * @mentcnt: ....
 */
void prompt_display(int mentcnt)
{
	if (isatty(STDIN_FILENO) && mentcnt != 2)
		write(1, disprompt, 2);
}
