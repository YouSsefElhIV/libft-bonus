/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:20:01 by yel-haya          #+#    #+#             */
/*   Updated: 2024/11/04 13:42:04 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*courant;
	t_list	*next_n;

	if (!del || !lst)
		return ;
	courant = *lst;
	while (courant)
	{
		next_n = courant->next;
		del(courant->content);
		free(courant);
		courant = next_n;
	}
	*lst = NULL;
}
