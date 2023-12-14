#include "monty.h"

/**
 * setOpTokError - Sets last element of op_toks to be an error code.
 * @errorCode: Integer to store as a string in op_toks.
 */
void setOpTokError(int errorCode)
{
	int tokensLength = 0, i = 0;
	char *exitString = NULL;
	char **newTokens = NULL;

	tokensLength = tokensArrLength();
	newTokens = malloc(sizeof(char *) * (tokensLength + 2));
	if (!op_toks)
	{
		mallocError();
		return;
	}
	while (i < tokensLength)
	{
		newTokens[i] = op_toks[i];
		i++;
	}
	exitString = getInt(errorCode);
	if (!exitString)
	{
		free(newTokens);
		mallocError();
		return;
	}
	newTokens[i++] = exitString;
	newTokens[i] = NULL;
	free(op_toks);
	op_toks = newTokens;
}

