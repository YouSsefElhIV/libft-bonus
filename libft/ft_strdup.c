/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 15:40:43 by yel-haya          #+#    #+#             */
/*   Updated: 2024/10/26 22:54:01 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*new_copy;

	new_copy = ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (new_copy == NULL)
		return (NULL);
	ft_strlcpy(new_copy, s1, ft_strlen(s1) + 1);
	return (new_copy);
}
