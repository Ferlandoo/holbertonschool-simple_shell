#include "main.h"

/**
 * main - Entry point
 * @argc: The number of arguments
 * @argv: The arguments
 * Return: 0 on success, 1 on failure
 */

int main(int __attribute__((unused)) argc, char *argv[])
{
	char *line = NULL;
	char* name;
	size_t buf_size = 0;
	int characters = 0;

	name = argv[0];
	while (1)
	{
		write(1, "Welcome to Shell $ ", 19);
		characters = getline(&line, &buf_size, stdin);
		if (characters == -1)
		{
			perror("Error");
			break;
		}
		if (line[characters - 1] == '\n')
			line[characters - 1] = '\0';
		if (*line == '\0')
			continue;
		if (command_read(line) == 2)
			break;
	}
	free(line);
	return (0);
}

/**
 * command_read - Reads a command from stdin
 * @s: The command to read
 * Return: 0 on success, 1 on failure
 */

int command_read(char *s)
{
	int i;
	char *token = NULL;
	char *cmd_array[100];

	if (strcmp(s, "exit") == 0)
		return (2);
	if (strcmp(s, "env") == 0)
		return (_printenv());
	i = 0;
	token = strtok(s, " ");
	while (token != NULL && i < 100)
	{
		cmd_array[i++] = token;
		token = strtok(NULL, " ");
	}
	cmd_array[i] = NULL;
	return (execute(cmd_array));
}

/**
 * execute - Executes a command
 * @cmd_arr: The command to execute
 * Return: 0 on success, 1 on failure
 */

int execute(char *cmd_arr[])
{
	pid_t pid;
	char *exe_path;
	int status;
	char *name;

	exe_path = command_path(cmd_arr[0]);
	if (exe_path == NULL)
	{
		fprintf(stderr, "%s: %s: not found", name, cmd_arr[0]);
		return (3);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("Error....");
		return (-1);
	}
	if (pid > 0)
	{
		wait(&status);
	}
	else
	{
		if (environ)
		{
			execve(exe_path, cmd_arr, environ);
			exit(1);
		}
		else
		{
			execve(exe_path, cmd_arr, NULL);
			exit(1);
		}
	}
	free(exe_path);
	return (0);
}
