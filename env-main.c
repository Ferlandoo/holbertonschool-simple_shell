#include "main.h"

int main()
{
	char *cmd, *path, *path_var;

	_printenv();

	path_var = _getenv("PATH");

	printf("Path variables\n %s\n", path_var);

	return (0);
}
