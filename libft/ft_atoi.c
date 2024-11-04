/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:55:23 by yel-haya          #+#    #+#             */
/*   Updated: 2024/11/01 10:57:29 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	spaces_check(const char *str, int *i)
{
	int	sign;

	sign = 1;
	while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
		(*i)++;
	if (str[*i] == '+')
		(*i)++;
	else if (str[*i] == '-')
	{
		sign = -1;
		(*i)++;
	}
	return (sign);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	res;
	int		sign;
	long	res2;

	res = 0;
	res2 = 0;
	i = 0;
	sign = spaces_check(str, &i);
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
	{
		if (res2 > (LONG_MAX - (str[i] - 48)) / 10)
		{
			if (sign == 1)
				return (-1);
			if (sign == -1)
				return (0);
		}
		res2 = res * 10 + (str[i] - 48);
		i++;
		res = res2;
	}
	return (((int)res * sign));
}
