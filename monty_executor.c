#include "monty.h"
#include <string.h>

void freeTokens(void);
unsigned int tokensLength(void);
int isLineEmpty(char *line, char *delimiters);
void (*getOperationFunction(char *opcode))(stack_t**, unsigned int);
int runMonty(FILE *script_fd);

/**
 * freeTokens - Frees the global op_toks array of strings.
 */
void freeTokens(void)
{
	size_t i = 0;

	if (op_toks == NULL)
		return;

	for (i = 0; op_toks[i]; i++)
		free(op_toks[i]);

	free(op_toks);
}

/**
 * tokensLength - Gets the length of current op_toks.
 *
 * Return: Length of current op_toks (as int).
 */
unsigned int tokensLength(void)
{
	unsigned int length = 0;

	while (op_toks[length])
		length++;
	return (length);
}

/**
 * isLineEmpty - Checks if a line read from getline only contains delimiters.
 * @line: A pointer to the line.
 * @delimiters: A string of delimiter characters.
 *
 * Return: If the line only contains delimiters - 1.
 *         Otherwise - 0.
 */
int isLineEmpty(char *line, char *delimiters)
{
	int i, j;

	for (i = 0; line[i]; i++)
	{
		for (j = 0; delimiters[j]; j++)
		{
			if (line[i] == delimiters[j])
				break;
		}
		if (delimiters[j] == '\0')
			return (0);
	}

	return (1);
}

/**
 * getOperationFunction - Matches an opcode with its corresponding function.
 * @opcode: The opcode to match.
 *
 * Return: A pointer to the corresponding function.
 */
void (*getOperationFunction(char *opcode))(stack_t**, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", montyPush},
		{"pall", montyPall},
		{"pint", montyPint},
		{"pop", montyPop},
		{"swap", montySwap},
		{"add", montyAdd},
		{"nop", montyNop},
		{"sub", montySub},
		{"div", montyDiv},
		{"mul", montyMul},
		{"mod", montyMod},
		{"pchar", montyPchar},
		{"pstr", montyPstr},
		{"rotl", montyRotl},
		{"rotr", montyRotr},
		{"stack", montyStack},
		{"queue", montyQueue},
		{NULL, NULL}
	};
	int i;

	for (i = 0; op_funcs[i].opcode; i++)
	{
		if (strcmp(opcode, op_funcs[i].opcode) == 0)
			return (op_funcs[i].f);
	}

	return (NULL);
}

/**
 * runMonty - Primary function to execute a Monty bytecodes script.
 * @script_fd: File descriptor for an open Monty bytecodes script.
 *
 * Return: EXIT_SUCCESS on success, respective error code on failure.
 */
int runMonty(FILE *script_fd)
{
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 0;
	unsigned int exit_status = EXIT_SUCCESS, line_number = 0, prev_token_len = 0;
	void (*op_func)(stack_t**, unsigned int);

	if (initializeStack(&stack) == EXIT_FAILURE)
		return (EXIT_FAILURE);

	while (getline(&line, &len, script_fd) != -1)
	{
		line_number++;
		op_toks = strtow(line, DELIMITERS);
		if (op_toks == NULL)
		{
			if (isLineEmpty(line, DELIMITERS))
				continue;
			freeStack(&stack);
			return (mallocError());
		}
		else if (op_toks[0][0] == '#') /* comment line */
		{
			freeTokens();
			continue;
		}
		op_func = getOperationFunction(op_toks[0]);
		if (op_func == NULL)
		{
			freeStack(&stack);
			exit_status = unknownOperationError(op_toks[0], line_number);
			freeTokens();
			break;
		}
		prev_token_len = tokensLength();
		op_func(&stack, line_number);
		if (tokensLength() != prev_token_len)
		{
			if (op_toks && op_toks[prev_token_len])
				exit_status = atoi(op_toks[prev_token_len]);
			else
				exit_status = EXIT_FAILURE;
			freeTokens();
			break;
		}
		freeTokens();
	}
	freeStack(&stack);

	if (line && *line == 0)
	{
		free(line);
		return (mallocError());
	}

	free(line);
	return (exit_status);
}

