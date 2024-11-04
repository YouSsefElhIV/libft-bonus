/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:52:54 by yel-haya          #+#    #+#             */
/*   Updated: 2024/11/01 11:29:17 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*st;

	i = 0;
	st = (const unsigned char *)s;
	while (i < n)
	{
		if (st[i] == (unsigned char) c)
			return ((void *)&st[i]);
		i++;
	}
	return (NULL);
}
