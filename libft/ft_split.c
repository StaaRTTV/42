/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpochon <gpochon@student.42luxembourg.l    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 10:18:26 by gpochon           #+#    #+#             */
/*   Updated: 2024/10/26 16:36:20 by gpochon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_count(const char *s, char c)
{
	size_t	count;
	size_t	is_word;

	count = 0;
	is_word = 0;
	while (*s)
	{
		if (*s != c && is_word == 0)
		{
			is_word = 1;
			count++;
		}
		else if (*s == c)
			is_word = 0;
		s++;
	}
	return (count);
}

static char	*malloc_words(const char *s, char c)
{
	int		len;
	int		i;
	char	*word;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	word = (char *)malloc(sizeof (char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = s[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static void	free_malloc(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

char	**ft_split(char const *str, char c)
{
	int		words;
	int		i;
	char	**split;

	i = 0;
	words = word_count(str, c);
	split = (char **)malloc(sizeof (char *) * (words + 1));
	if (!str || !split)
		return (NULL);
	while (*str)
	{
		if (*str != c)
		{
			split[i] = malloc_words(str, c);
			if (!split[i++])
				return (free_malloc(split, i - 1), NULL);
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	split[i] = NULL;
	return (split);
}
