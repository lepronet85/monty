#include "monty.h"

void addStackValues(stack_t **stack, unsigned int line_number);
void subtractStackValues(stack_t **stack, unsigned int line_number);
void divideStackValues(stack_t **stack, unsigned int line_number);
void multiplyStackValues(stack_t **stack, unsigned int line_number);
void computeModulus(stack_t **stack, unsigned int line_number);

/**
 * addStackValues - Adds the top two values of a stack_t linked list.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value  is removed.
 */
void addStackValues(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOpTokError(shortStackError(line_number, "add"));
		return;
	}

	(*stack)->next->next->n += (*stack)->next->n;
	popFromStack(stack, line_number);
}

/**
 * subtractStackValues - Subtracts the second value from the top of
 *                       a stack_t linked list by the top value.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void subtractStackValues(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOpTokError(shortStackError(line_number, "sub"));
		return;
	}

	(*stack)->next->next->n -= (*stack)->next->n;
	popFromStack(stack, line_number);
}

/**
 * divideStackValues - Divides the second value from the top of
 *                     a stack_t linked list by the top value.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void divideStackValues(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOpTokError(shortStackError(line_number, "div"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		setOpTokError(divError(line_number));
		return;
	}

	(*stack)->next->next->n /= (*stack)->next->n;
	popFromStack(stack, line_number);
}

/**
 * multiplyStackValues - Multiplies the second value from the top of
 *                       a stack_t linked list by the top value.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void multiplyStackValues(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOpTokError(shortStackError(line_number, "mul"));
		return;
	}

	(*stack)->next->next->n *= (*stack)->next->n;
	popFromStack(stack, line_number);
}

/**
 * computeModulus - Computes the modulus of the second value from the
 *                  top of a stack_t linked list by the top value.
 * @stack: Pointer to the top node of a stack_t linked list.
 * @line_number: Current line number in a Monty bytecodes file.
 *
 * Description: The result is stored in the second value node
 *              from the top and the top value is removed.
 */
void computeModulus(stack_t **stack, unsigned int line_number)
{
	if ((*stack)->next == NULL || (*stack)->next->next == NULL)
	{
		setOpTokError(shortStackError(line_number, "mod"));
		return;
	}

	if ((*stack)->next->n == 0)
	{
		setOpTokError(divError(line_number));
		return;
	}

	(*stack)->next->next->n %= (*stack)->next->n;
	popFromStack(stack, line_number);
}

