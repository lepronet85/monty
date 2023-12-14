#include <stdlib.h>

char **tokenizeString(char *str, char *delims);
int isDelimiter(char ch, char *delims);
int wordLength(char *str, char *delims);
int wordCount(char *str, char *delims);
char *getNextWord(char *str, char *delims);

/**
 * tokenizeString - Separates a string into words.
 *
 * @str: String to separate into words.
 * @delims: Delimiters to use for word separation.
 *
 * Return: 2D array of pointers to each word.
 */
char **tokenizeString(char *str, char *delims)
{
	char **words = NULL;
	int wc, wordLen, n, i = 0;

	if (str == NULL || !*str)
		return (NULL);
	wc = wordCount(str, delims);

	if (wc == 0)
		return (NULL);
	words = malloc((wc + 1) * sizeof(char *));
	if (words == NULL)
		return (NULL);
	while (i < wc)
	{
		wordLen = wordLength(str, delims);
		if (isDelimiter(*str, delims))
		{
			str = getNextWord(str, delims);
		}
		words[i] = malloc((wordLen + 1) * sizeof(char));
		if (words[i] == NULL)
		{
			while (i >= 0)
			{
				i--;
				free(words[i]);
			}
			free(words);
			return (NULL);
		}
		n = 0;
		while (n < wordLen)
		{
			words[i][n] = *(str + n);
			n++;
		}
		words[i][n] = '\0'; /* set end of str */
		str = getNextWord(str, delims);
		i++;
	}
	words[i] = NULL; /* last element is null for iteration */
	return (words);
}

/**
 * isDelimiter - Checks if a character is a delimiter.
 *
 * @ch: Character to check.
 * @delims: Pointer to a null-terminated array of delimiters.
 *
 * Return: 1 (true) or 0 (false).
 */
int isDelimiter(char ch, char *delims)
{
	int i = 0;

	while (delims[i])
	{
		if (delims[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

/**
 * wordLength - Gets the length of the current word in a string.
 *
 * @str: String to get word length from.
 * @delims: Delimiters to use for word separation.
 *
 * Return: Word length of the current word.
 */
int wordLength(char *str, char *delims)
{
	int wLen = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (isDelimiter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			wLen++;
		}
		if (wLen > 0 && isDelimiter(str[i], delims))
			break;
		i++;
	}
	return (wLen);
}

/**
 * wordCount - Gets the word count in a string.
 *
 * @str: String to get word count from.
 * @delims: Delimiters to use for word separation.
 *
 * Return: The word count of the string.
 */
int wordCount(char *str, char *delims)
{
	int wc = 0, pending = 1, i = 0;

	while (*(str + i))
	{
		if (isDelimiter(str[i], delims))
			pending = 1;
		else if (pending)
		{
			pending = 0;
			wc++;
		}
		i++;
	}
	return (wc);
}

/**
 * getNextWord - Gets the next word in a string.
 *
 * @str: String to get next word from.
 * @delims: Delimiters to use for word separation.
 *
 * Return: Pointer to the first character of the next word.
 */
char *getNextWord(char *str, char *delims)
{
	int pending = 0;
	int i = 0;

	whil

