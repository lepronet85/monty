#include "monty.h"

/**
 * monty_rotl - Rotates the stack_t linked list, moving the top element to the bottom.
 * @stack: Pointer to the top mode node of a stack_t linked list.
 * @line_number: Current line number in the Monty bytecode file being processed.
 * Return: Nothing (void)
 */

void monty_rotl(stack_t **stack, unsigned int line_number)
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
 * monty_rotr - Rotates the bottom value of a stack_t linked list to the top.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @line_number: The current working line number of a Monty bytecodes file.
 * Return: Nothing (void)
 */
void monty_rotr(stack_t **stack, unsigned int line_number)
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
 * monty_stack - Transforms a queue into a stack.
 * @stack: Pointer to the topmost node in a stack_t linked list.
 * @line_number: Current line number in the Monty bytecode file.
 * Return: Nothing (void)
 */

void monty_stack(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = STACK;
	(void)line_number;
}

/**
 * monty_queue - Converts the stack into a queue.
 * @stack: A pointer to the top node of a stack_t linked list.
 * @line_number: The current line number in the Monty bytecode file.
 * Return: Nothing (void)
 */

void monty_queue(stack_t **stack, unsigned int line_number)
{
	(*stack)->n = QUEUE;
	(void)line_number;
}