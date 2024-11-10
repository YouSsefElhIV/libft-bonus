/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:10:55 by yel-haya          #+#    #+#             */
/*   Updated: 2024/11/01 11:08:40 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	const char	*s;
	char		*d;

	s = (const char *)src;
	d = (char *)dst;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	if (src == dst)
		return ((void *)src);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
