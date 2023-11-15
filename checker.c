#include "shelly.h"
/**
 * confirm_refe - check ref
 * @ment: pointer
 */
void confirm_refe(char **ment)
{
	int x = 0;

	while (ment[x] != NULL)
	{
		if (ment[x][0] == '\'')
			ment[x] = strdup(strtok(ment[x], "'"));
		else if (ment[x][0] == '\"')
			ment[x] = strdup(strtok(ment[x], "\""));
		x++;
	}
}

/**
 * confirm_ref - confirm
 * @ment: pointer
 * Return: pointer
 */
char *confirm_ref(char *ment)
{
	if (ment[0] == '\'')
		ment = strdup(strtok(ment, "'"));
	else if (ment[0] == '\"')
		ment = strdup(strtok(ment, "\""));
	return (ment);
}
