#include <stdlib.h>

char *getIntString(int num);
unsigned int getAbsoluteValue(int);
int getNumBaseLength(unsigned int num, unsigned int base);
void fillNumBaseBuffer(unsigned int num, unsigned int base,
                       char *buff, int buff_size);

/**
 * getIntString - Retrieves a character pointer to a new string containing an integer.
 * @num: Number to convert to string.
 *
 * Return: Character pointer to the newly created string. NULL if malloc fails.
 */
char *getIntString(int num)
{
	unsigned int temp;
	int length = 0;
	long num_l = 0;
	char *ret;

	temp = getAbsoluteValue(num);
	length = getNumBaseLength(temp, 10);

	if (num < 0 || num_l < 0)
		length++; /* Accounts for negative sign */

	ret = malloc(length + 1); /* Create a new string */
	if (!ret)
		return (NULL);

	fillNumBaseBuffer(temp, 10, ret, length);
	if (num < 0 || num_l < 0)
		ret[0] = '-';

	return (ret);
}

/**
 * getAbsoluteValue - Retrieves the absolute value of an integer.
 * @i: Integer to obtain absolute value of.
 *
 * Return: Unsigned integer representing the absolute value of 'i'.
 */
unsigned int getAbsoluteValue(int i)
{
	if (i < 0)
		return (-(unsigned int)i);
	return ((unsigned int)i);
}

/**
 * getNumBaseLength - Retrieves the length of buffer needed for an unsigned int.
 * @num: Number to obtain length needed for.
 * @base: Base of number representation used by buffer.
 *
 * Return: Integer containing the length of buffer needed (doesn't contain null byte).
 */
int getNumBaseLength(unsigned int num, unsigned int base)
{
	int len = 1; /* All numbers contain at least one digit */

	while (num > base - 1)
	{
		len++;
		num /= base;
	}
	return (len);
}

/**
 * fillNumBaseBuffer - Fills the buffer with correct numbers up to base 36.
 * @num: Number to convert to string given base.
 * @base: Base of number used in conversion (works up to base 36).
 * @buff: Buffer to fill with the result of conversion.
 * @buff_size: Size of buffer in bytes.
 *
 * Return: Always void.
 */
void fillNumBaseBuffer(unsigned int num, unsigned int base,
                       char *buff, int buff_size)
{
	int rem, i = buff_size - 1;

	buff[buff_size] = '\0';
	while (i >= 0)
	{
		rem = num % base;
		if (rem > 9) /* Return lowercase ASCII val representation */
			buff[i] = rem + 87; /* 10 will be 'a', 11 will be 'b', ... */
		else
			buff[i] = rem + '0';
		num /= base;
		i--;
	}
}

