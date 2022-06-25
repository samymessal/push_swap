/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 13:46:19 by smessal           #+#    #+#             */
/*   Updated: 2022/06/24 21:17:20 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!lst || !new)
		return ;
	last = *lst;
	if (!last)
	{
		*lst = new;
		return ;
	}
	while (last -> next)
		last = last -> next;
	last -> next = new;
	return ;
}
