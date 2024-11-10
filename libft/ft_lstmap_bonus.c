/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-haya <yel-haya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:48:13 by yel-haya          #+#    #+#             */
/*   Updated: 2024/11/04 14:42:30 by yel-haya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_head;
	t_list	*new_n;
	void	*cont;

	new_head = NULL;
	if (!f || !lst)
		return (NULL);
	while (lst)
	{
		cont = f(lst->content);
		new_n = ft_lstnew(cont);
		if (!new_n)
		{
			del(cont);
			ft_lstclear(&new_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_head, new_n);
		lst = lst->next;
	}
	return (new_head);
}
