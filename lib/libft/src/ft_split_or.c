/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split_or.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/12/22 22:18:54 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/25 18:13:21 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

static size_t	count_words(char *s, char *splitters)
{
	char	*sep;
	size_t	words;

	sep = s - 1;
	words = 0;
	while (true)
	{
		if (ft_includes(splitters, *s) || *s == '\0')
		{
			if (s - sep > 1)
				words++;
			if (*s == '\0')
				return (words);
			sep = s;
		}
		s++;
	}
}

static void		free_strings(char **strings, size_t n)
{
	while (n > 0)
	{
		n--;
		if (strings[n] != NULL)
			free(strings[n]);
	}
	free(strings);
}

static void		cpy_words(\
char *s, char *splitters, char **split, size_t num_words)
{
	char	*sep;
	size_t	word_i;

	sep = s - 1;
	word_i = 0;
	while (word_i < num_words)
	{
		if (ft_includes(splitters, *s) || *s == '\0')
		{
			if (s - sep > 1)
			{
				split[word_i] = ft_strndup_unsafe(
					sep + 1, (size_t)(s - sep - 1));
				if (split[word_i] == NULL)
				{
					free_strings(split, word_i);
					return ;
				}
				word_i++;
			}
			sep = s;
		}
		s++;
	}
	split[num_words] = NULL;
}

/*
** @description split string s in array of strings, followed by a NULL
**              using any of the character in splitters.
**              ft_split_or("foo,,bar", ",a") --> {"foo", "b", "r", NULL}
*/

char			**ft_split_or(const char *s, const char *spitters)
{
	char	**split;
	size_t	num_words;

	num_words = count_words((char *)s, (char *)spitters);
	split = malloc((num_words + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	cpy_words((char *)s, (char *)spitters, split, num_words);
	return (split);
}
