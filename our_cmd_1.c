#include "shelly.h"
/**
 * root_check - change dir
 * @ment: double pointer
 * @m: pointer
 */
void root_check(char **ment, __attribute__((unused))line_up **m)
{
	char *f = NULL;
	size_t n = 0;
	struct stat ff;

	if (getenv("OLDPWD") == NULL)
		setenv("OLDPWD", getcwd(f, n), 1);
	if (ment[1] == NULL)
	{
		chdir("/root");
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", "/root", 1);
	}
	else if (strcmp(ment[1], "-") == 0)
	{
		chdir(getenv("OLDPWD"));
		setenv("OLDPWD", getenv("PWD"), 1);
		setenv("PWD", getcwd(f, n), 1);
	}
	else
	{
		stat(ment[1], &ff);
		if (S_ISDIR(ff.st_mode))
		{
			chdir(ment[1]);
			setenv("OLDPWD", getenv("PWD"), 1);
			setenv("PWD", ment[1], 1);
		}
	}
	free(f);
}

/**
 * environ_set - set env var
 * @ment: double pointer
 * @m: pointer
 */
void environ_set(char **ment, __attribute__((unused))line_up **m)
{
	int r;

	r = setenv(ment[1], ment[2], 1);
	if (r == -1)
		dprintf(STDERR_FILENO, "cannot setenv\n");
}

/**
 * environ_unset - removes env var
 * @ment: double pointer
 * @m: pointer
 */
void environ_unset(char **ment, __attribute__((unused))line_up **m)
{
	int r;

	r = unsetenv(ment[1]);

	if (r == -1)
		dprintf(STDERR_FILENO, "cannot unsetenv\n");
}
