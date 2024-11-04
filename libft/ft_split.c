/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 18:23:32 by yel-haya          #+#    #+#             */
/*   Updated: 2024/10/30 15:43:39 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*allocate_word(const char *s, int start, int end)
{
	char	*word;

	word = (char *)malloc(end - start + 1);
	if (!word)
		return (NULL);
	ft_strlcpy(word, s + start, end - start + 1);
	return (word);
}

static void	free_memory(char **f, int i)
{
	while (i > 0)
		free(f[--i]);
	free(f);
}

static int	split_words(char **f, const char *s, char c, int total_words)
{
	int	endings;
	int	i;
	int	start;

	endings = 0;
	i = 0;
	while (i < total_words)
	{
		while (s[endings] == c)
			endings++;
		start = endings;
		while (s[endings] && s[endings] != c)
			endings++;
		f[i] = allocate_word(s, start, endings);
		if (!f[i])
		{
			free_memory(f, i);
			return (0);
		}
		i++;
	}
	f[i] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**f;
	int		total_words;

	if (!s)
		return (NULL);
	total_words = count_words(s, c);
	f = (char **)malloc((total_words + 1) * sizeof(char *));
	if (!f)
		return (NULL);
	if (split_words(f, s, c, total_words) == 0)
	{
		return (NULL);
	}
	return (f);
}
