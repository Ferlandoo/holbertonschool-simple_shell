#include "main.h"

int _printenv()
{
	int i = 0;
	int file_descr = 1;

	if (environ == NULL)
	{
		fprintf(stderr, "Error\n");
		return (-1);

	}

	while(environ[i] != NULL)
	{
		write(file_descr, environ[i], strlen(environ[i]));
		write(file_descr, "\n" ,1);
		i++;
	}
	return (0);
}

char *_getenv(char *var)
{
	int i, len_var;
	if (environ == NULL)
        {
                fprintf(stderr, "Error\n");
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
