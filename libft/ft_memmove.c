/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 13:23:01 by yel-haya          #+#    #+#             */
/*   Updated: 2024/11/01 09:22:58 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	the_moving(const char *s, char *d, size_t len)
{
	size_t	i;

	i = 0;
	if (s >= d)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else if (s < d)
	{
		i = len;
		while (i > 0)
		{
			d[i - 1] = s[i - 1];
			i--;
		}
	}
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	s = (const char *)src;
	d = (char *)dst;
	if (dst == src || len == 0)
		return (dst);
	the_moving(s, d, len);
	return (dst);
}
