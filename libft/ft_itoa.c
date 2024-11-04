/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 00:17:55 by yel-haya          #+#    #+#             */
/*   Updated: 2024/11/01 12:04:03 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static long	is_neg(long n, int neg, char *res)
{
	if (neg == 1)
	{
		res[0] = '-';
		n = -n;
	}
	return (n);
}

static void	the_conv(long nb, int neg, char *res)
{
	int	i;
	int	digits;

	digits = count_digits(nb);
	i = 0;
	if (nb > 9)
	{
		i = digits - 1 + neg;
		while (nb > 0)
		{
			res[i] = (nb % 10) + '0';
			nb = nb / 10;
			i--;
		}
	}
}

char	*ft_itoa(int n)
{
	char	*res;
	int		neg;
	int		digits;
	long	nb;

	nb = n;
	digits = count_digits(nb);
	neg = 0;
	if (nb < 0)
		neg = 1;
	res = (char *) malloc (digits + neg + 1);
	if (res == NULL)
		return (NULL);
	nb = is_neg(nb, neg, res);
	res[digits + neg] = '\0';
	if (nb >= 0 && nb <= 9)
	{
		res[neg] = nb + '0';
		return (res);
	}
	the_conv(nb, neg, res);
	return (res);
}
