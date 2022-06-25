/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:26:36 by smessal           #+#    #+#             */
/*   Updated: 2022/05/17 15:45:03 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*res;

	tmp = NULL;
	while (lst)
	{
		res = ft_lstnew(f(lst->content));
		if (!res)
		{
			ft_lstclear(&tmp, del);
			return (NULL);
		}
		ft_lstadd_back(&tmp, res);
		lst = lst->next;
	}
	return (tmp);
}
