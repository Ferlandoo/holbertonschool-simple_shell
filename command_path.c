#include "main.h"

char *command_path(char *cmd)
{
	char *path, *path_copy, *full_path, *token;

	path = _getenv("PATH");
	if (path == NULL)
	{
		fprintf(stderr, "Error");
		return (NULL);
	}

	path_copy = strdup(path);
	if (path_copy == NULL)
	{
		fprintf(stderr, "Error");
                return (NULL);
	}
	token = strtok(path_copy, ":");
	while (token != NULL)
	{
		full_path = malloc(sizeof(strlen(token) + strlen(cmd) + 2));
		if (full_path == NULL)
		{
			fprintf(stderr, "Error");
                	free(path_copy);
			return (NULL);
		}
		strcpy(full_path, token);
		strcpy(full_path, "/");
		strcpy(full_path, cmd);

		token = strtok(NULL, ":")
	}
	free(full_path);
	free(path_copy);
	return (full_path);
}
