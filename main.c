#include "monty.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char **tokens = NULL;

/**
 * main - Entry point for Monty Interpreter
 *
 * @argc: Count of arguments passed to the program
 * @argv: Pointer to an array of char pointers to arguments
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on error
 */
int main(int argc, char **argv)
{
	FILE *script_file = NULL;
	int exit_status = EXIT_SUCCESS;

	if (argc != 2)
		return (printUsageError());
	
	script_file = fopen(argv[1], "r");
	if (script_file == NULL)
		return (printFileOpenError(argv[1]));
	
	exit_status = runMonty(script_file);
	fclose(script_file);
	
	return (exit_status);
}

