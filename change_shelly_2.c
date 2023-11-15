#include "shelly.h"
/**
 * main - shelly
 * @mentcnt: arg count
 * @mentnum: array
 * Return: 0
 */
int main(int mentcnt, __attribute__((unused))char **mentnum)
{
	int u;
	int v = 0;
	char *list = NULL;
	char **mentg = NULL;
	size_t n = 0;
	line_up *m = NULL;
	line_up *mm = NULL;

	plus_line_up(&mm, "?", "0");
	if (mentcnt == 2)
	{
		scroll(mentnum, m, mm);
	}
	else if (mentcnt == 1)
	{
		prompt_display(mentcnt);
		while ((u = getline(&list, &n, stdin)) != -1)
		{
			tabchk(&list);
			if (u == 1 || list[0] == '\n')
			{
				write(1, disprompt, 2);
				continue;
			}
			v++;
			mentg = lineexecs(list, &m, &mm);
			if (mentg != NULL)
				mischk(mentnum[0], mentg[0], v);
			prompt_display(mentcnt);
		}
	}
	if (u == -1 && isatty(STDIN_FILENO) && mentcnt != 2)
		printf("\n");
	free(mentg);
	free(list);
	line_release(m);
	line_release(mm);
	return (0);
}

/**
 * scroll - file handler
 * @mentnum: ....
 * @m: ...
 * @mm: ...
 */
void scroll(char **mentnum, line_up *m, line_up *mm)
{
	size_t n = 1024;
	FILE *z;
	char **mentg = NULL;
	char *list = NULL;
	int v = 0;

	z = fopen(mentnum[1], "r");
	if (z == NULL)
		mischk(mentnum[0], mentnum[1], v);
	else
	{
		list = malloc(sizeof(char) * n);
		while (fgets(list, n, z) != NULL)
		{
			v++;
			mentg = lineexecs(list, &m, &mm);
			if (mentg != NULL)
				mischk(mentnum[0], mentg[0], v);
		}
		fclose(z);
	}
}

/**
 * mischk - err check
 * @vk: pointer
 * @mentg: ...
 * @v: ...
 */
void mischk(char *vk, char *mentg, int v)
{
	dprintf(STDOUT_FILENO, "%s: %d: ", vk, v);
	perror(mentg);
}
