/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:21:12 by yel-haya          #+#    #+#             */
/*   Updated: 2024/10/26 22:51:20 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	while (i > 0)
	{
		if (s[i - 1] == (char) c)
			return ((char *)&s[i - 1]);
		i--;
	}
	return (NULL);
}
