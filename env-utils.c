#include "main.h"

/**
 * _printenv - Prints the environment
 * @void: void
 * Return: 0 on success, -1 on failure
 */

int _printenv(void)
{
	int i, file_descr = 1;

	if (environ == NULL)
	{
		fprintf(stderr, "Environment variable is null");
		return (-1);
	}
	i = 0;
	while (environ[i] != NULL)
	{
		write(file_descr, environ[0], strlen(environ[0]));
		write(file_descr, "\n", 1);
		environ[i];
		++i;
	}
	return (0);
}

/**
 * _getenv - Gets the value of an environment variable
 * @var: The environment variable to get
 * Return: The value of the environment variable
 */

char *_getenv(char *var)
{
	int i, len_var;

	if (environ == NULL)
	{
		fprintf(stderr, "Environment variable is null");
		return (NULL);
	}
	len_var = strlen(var);
	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], var, len_var) == 0)
			return (&environ[i][len_var]);
	}
	return (NULL);
}
