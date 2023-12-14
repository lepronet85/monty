#include "monty.h"

void doNothing(stack_t **stack, unsigned int line_number);
void printCharacter(stack_t **stack, unsigned int line_number);
void printString(stack_t **stack, unsigned int line_number);

/**
 * doNothing - Does absolutely nothing for the Monty opcode 'nop'.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 */
void doNothing(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * printCharacter - Prints the character in the top value
 *                  node of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 */
void printCharacter(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		setOpTokError(pcharError(line_number, "stack empty"));
		return;
	}
	if ((*stack)->next->n < 0 || (*stack)->next->n > 127)
	{
		setOpTokError(pcharError(line_number, "value out of range"));
		return;
	}

	printf("%c\n", (*stack)->next->n);
}

/**
 * printString - Prints the string contained in a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 */
void printString(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp && tmp->n != 0 && (tmp->n > 0 && tmp->n <= 127))
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}

	printf("\n");

	(void)line_number;
}

