#include "monty.h"

int printUsageError(void);
int printMallocError(void);
int printFileOpenError(char *filename);
int printUnknownOpError(char *opcode, unsigned int lineNumber);
int printNoIntError(unsigned int lineNumber);

/**
 * printUsageError - Outputs usage-related error messages.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int printUsageError(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	return (EXIT_FAILURE);
}

/**
 * printMallocError - Outputs malloc-related error messages.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int printMallocError(void)
{
	fprintf(stderr, "Error: Memory allocation failed\n");
	return (EXIT_FAILURE);
}

/**
 * printFileOpenError - Outputs file opening error messages with the file name.
 * @filename: Name of the file that failed to open.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int printFileOpenError(char *filename)
{
	fprintf(stderr, "Error: Failed to open file %s\n", filename);
	return (EXIT_FAILURE);
}

/**
 * printUnknownOpError - Outputs error messages for unknown instructions.
 * @opcode: The opcode where the error occurred.
 * @lineNumber: Line number in the Monty bytecode file where the error occurred.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int printUnknownOpError(char *opcode, unsigned int lineNumber)
{
	fprintf(stderr, "L%u: Unknown instruction '%s'\n",
		lineNumber, opcode);
	return (EXIT_FAILURE);
}

/**
 * printNoIntError - Outputs error messages for invalid 'push' arguments.
 * @lineNumber: Line number in the Monty bytecode file where the error occurred.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int printNoIntError(unsigned int lineNumber)
{
	fprintf(stderr, "L%u: Usage: push integer\n", lineNumber);
	return (EXIT_FAILURE);
}

