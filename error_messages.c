#include "monty.h"

int printShortStackError(unsigned int lineNumber, char *operation);
int printDivError(unsigned int lineNumber);
int printPopError(unsigned int lineNumber);
int printPintError(unsigned int lineNumber);
int printPcharError(unsigned int lineNumber, char *message);

/**
 * printPopError - Outputs 'pop' error messages for empty stacks.
 * @lineNumber: Line number in the script where the error occurred.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int printPopError(unsigned int lineNumber)
{
	fprintf(stderr, "L%u: Cannot pop from an empty stack\n", lineNumber);
	return (EXIT_FAILURE);
}

/**
 * printPintError - Outputs 'pint' error messages for empty stacks.
 * @lineNumber: Line number in the Monty bytecode file where the error occurred.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int printPintError(unsigned int lineNumber)
{
	fprintf(stderr, "L%d: Cannot pint, stack is empty\n", lineNumber);
	return (EXIT_FAILURE);
}

/**
 * printShortStackError - Outputs math function error messages
 *                       for stacks/queues smaller than two nodes.
 * @lineNumber: Line number in the Monty bytecode file where the error occurred.
 * @operation: Operation where the error occurred.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int printShortStackError(unsigned int lineNumber, char *operation)
{
	fprintf(stderr, "L%u: Cannot perform %s, stack is too short\n", lineNumber, operation);
	return (EXIT_FAILURE);
}

/**
 * printDivError - Outputs division error messages for division by zero.
 * @lineNumber: Line number in the Monty bytecode file where the error occurred.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int printDivError(unsigned int lineNumber)
{
	fprintf(stderr, "L%u: Division by zero\n", lineNumber);
	return (EXIT_FAILURE);
}

/**
 * printPcharError - Outputs 'pchar' error messages for empty stacks
 *                   and non-character values.
 * @lineNumber: Line number in the Monty bytecode file where the error occurred.
 * @message: The corresponding error message to print.
 *
 * Return: Always returns (EXIT_FAILURE).
 */
int printPcharError(unsigned int lineNumber, char *message)
{
	fprintf(stderr, "L%u: Cannot pchar, %s\n", lineNumber, message);
	return (EXIT_FAILURE);
}

