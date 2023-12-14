#include "monty.h"

void rotateLeft(stack_t **stack, unsigned int line_number);
void rotateRight(stack_t **stack, unsigned int line_number);
void convertToStack(stack_t **stack, unsigned int line_number);
void convertToQueue(stack_t **stack, unsigned int line_number);

/**
 * rotateLeft - Rotates the top value of a stack_t linked list to the bottom.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 */
void rotateLeft(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	top->next->prev = *stack;
	(*stack)->next = top->next;
	bottom->next = top;
	top->next = NULL;
	top->prev = bottom;

	(void)line_number;
}

/**
 * rotateRight - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 */
void rotateRight(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
		return;

	top = (*stack)->next;
	bottom = (*stack)->next;
	while (bottom->next != NULL)
		bottom = bottom->next;

	bottom->prev->next = NULL;
	(*stack)->next = bottom;
	bottom->prev = *stack;
	bottom->next = top;
	top->prev = bottom;

	(void)line_number;
}

/**
 * convertToStack - Converts a queue to a stack.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 */
void convertToStack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * convertToQueue - Converts a stack to a queue.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 */
void convertToQueue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}

