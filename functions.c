#include "main.h"

/**
 * _isspace - checks if character is a space
 * @c: character to check
 * Return: 1 if true, 0 if false
*/

int _isspace(int c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v' || c == '\f')
	{
		return (1);
	}
	return (0);
}

/**
 * trim - removes leading and trailing whitespace from string
 * @str: string to trim
 * Return: trimmed string
*/

char *trim(char *str)
{
	char *end = str + strlen(str) - 1;

	while (_isspace(*str))
	{
		str++;
	}

	if (*str == 0)
	{
		return (str);
	}

	while (end > str && _isspace(*end))
	{
		end--;
	}

	end[1] = '\0';

	return (str);
}

/**
 * tokenize - tokenizes a string
 * @input: string to tokenize
 * Return: tokenized string
*/

char **tokenize(char *input)
{
	char **tokens = malloc(64 * sizeof(char *));
	char *token;
	int i = 0;

	if (!tokens)
	{
		fprintf(stderr, "hsh: allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input, " \t\r\n\a");

	while (token != NULL)
	{
		tokens[i] = token;
		i++;

		token = strtok(NULL, " \t\r\n\a");
	}

	tokens[i] = NULL;
	return (tokens);
}
