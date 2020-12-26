/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_spit.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jkoers <jkoers@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 11:59:38 by jkoers        #+#    #+#                 */
/*   Updated: 2020/12/22 22:32:18 by jkoers        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

static size_t	count_words(char *s, char c)
{
	char	*sep;
	size_t	words;

	sep = s - 1;
	words = 0;
	while (true)
	{
		if (*s == c || *s == '\0')
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
		free(strings[n]);
	}
	free(strings);
}

static void		cpy_words(char *s, char c, char **split, size_t num_words)
{
	char	*sep;
	size_t	word_i;

	sep = s - 1;
	word_i = 0;
	while (word_i < num_words)
	{
		if (*s == c || *s == '\0')
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

char			**ft_split(char const *s, char c)
{
	char	**split;
	size_t	num_words;

	num_words = count_words((char *)s, c);
	split = malloc((num_words + 1) * sizeof(char *));
	if (split == NULL)
		return (NULL);
	cpy_words((char *)s, c, split, num_words);
	return (split);
}
