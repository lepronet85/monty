#include "monty.h"
#include <stdlib.h>

/**
 * int_to_string - Converts an integer to a string representation
 * @num: The number to convert to a string
 *
 * Return: A pointer to a newly created string representation of the number.
 *          Returns NULL if memory allocation fails.
 */

char *get_int(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = _abs(num);
	length = get_numbase_len(temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* negative sign */
	ret = malloc(length + 1); /* create new string */
	if (!ret)
		return (NULL);

	fill_numbase_buff(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * _abs - computes the absolute value of an integer
 * @i: integer for which to compute the absolute value
 *
 * Return: unsigned integer representing the absolute value of i
 */

unsigned int _abs(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * get_numbase_len - Calculates the required buffer length for an unsigned int
 * @num: The number for which the length of the buffer is required
 * @base: The base of the number representation used by the buffer
 *
 * Return: An integer denoting the length of the buffer needed (excluding null byte)
 */

int get_numbase_len(unsigned int num, unsigned int base)
{
	int len = 1; /* all numbers contain atleast one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fill_numbase_buff - Converts a number to its string representation in the specified base.
 * @num: The number to convert to a string in the given base.
 * @base: The base of the number used in the conversion, supports up to base 36.
 * @buff: The buffer to fill with the result of the conversion.
 * @buff_size: The size of the buffer in bytes.
 *
 * This function converts the given number to its string representation in the specified base
 * and fills the provided buffer with the result. It supports bases up to 36.
 *
 * Return: This function always returns void.
 */

void fill_numbase_buff(unsigned int num, unsigned int base,
			char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* return lowercase ascii val representation */
			buff[i] = rem + 87; /* 10 will be a, 11 = b, ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}