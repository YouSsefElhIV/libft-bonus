/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:02:05 by yel-haya          #+#    #+#             */
/*   Updated: 2024/11/01 10:02:06 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	the_joining(char const *s1, char const *s2, size_t *i, char *f)
{
	size_t	j;

	while (*i < ft_strlen(s1))
	{
		f[*i] = s1[*i];
		(*i)++;
	}
	j = 0;
	while (j < ft_strlen(s2))
	{
		f[*i] = s2[j];
		(*i)++;
		j++;
	}
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*f;

	i = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	f = ft_calloc ((ft_strlen(s1) + ft_strlen(s2) + 1), sizeof(char));
	if (f == NULL)
		return (NULL);
	the_joining(s1, s2, &i, f);
	f[i] = '\0';
	return (f);
}
