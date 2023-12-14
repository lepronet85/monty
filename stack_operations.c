#include "monty.h"

void pushToStack(stack_t **stack, unsigned int line_number);
void printStack(stack_t **stack, unsigned int line_number);
void printTop(stack_t **stack, unsigned int line_number);
void popFromStack(stack_t **stack, unsigned int line_number);
void swapTop(stack_t **stack, unsigned int line_number);

/**
 * pushToStack - Pushes a value onto a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 */
void pushToStack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp, *newNode;
	int i;

	newNode = malloc(sizeof(stack_t));
	if (newNode == NULL)
	{
		setOpTokError(mallocError());
		return;
	}

	if (opTokens[1] == NULL)
	{
		setOpTokError(noIntError(line_number));
		return;
	}

	for (i = 0; opTokens[1][i]; i++)
	{
		if (opTokens[1][i] == '-' && i == 0)
			continue;
		if (opTokens[1][i] < '0' || opTokens[1][i] > '9')
		{
			setOpTokError(noIntError(line_number));
			return;
		}
	}
	newNode->n = atoi(opTokens[1]);

	if (checkMode(*stack) == STACK) /* Insert at the front for STACK mode */
	{
		tmp = (*stack)->next;
		newNode->prev = *stack;
		newNode->next = tmp;
		if (tmp)
			tmp->prev = newNode;
		(*stack)->next = newNode;
	}
	else /* Insert at the end for QUEUE mode */
	{
		tmp = *stack;
		while (tmp->next)
			tmp = tmp->next;
		newNode->prev = tmp;
		newNode->next = NULL;
		tmp->next = newNode;
	}
}

/**
 * printStack - Prints the values of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 */
void printStack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = (*stack)->next;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
	(void)line_number;
}

/**
 * printTop - Prints the top value of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 */
void printTop(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL)
	{
		setOpTokError(printTopError(line_number));
		return;
	}

	printf("%d\n", (*stack)->next->n);
}

/**
 * popFromStack - Removes the top value element of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 */
void popFromStack(stack_t **stack, unsigned int line_number)
{
	stack_t *nextNode = NULL;

	if ((*stack)->next == NULL)
	{
		setOpTokError(popError(line_number));
		return;
	}

	nextNode = (*stack)->next->next;
	free((*stack)->next);
	if (nextNode)
		nextNode->prev = *stack;
	(*stack)->next = nextNode;
}

/**
 * swapTop - Swaps the top two value elements of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 */
void swapTop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmpNode;

	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOpTokError(shortStackError(line_number, "swap"));
		return;
	}

	tmpNode = (*stack)->next->next;
	(*stack)->next->next = tmpNode->next;
	(*stack)->next->prev = tmpNode;
	if (tmpNode->next)
		tmpNode->next->prev = (*stack)->next;
	tmpNode->next = (*stack)->next;
	tmpNode->prev = *stack;
	(*stack)->next = tmpNode;
}

