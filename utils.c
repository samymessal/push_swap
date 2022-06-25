/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:40 by smessal           #+#    #+#             */
/*   Updated: 2022/06/25 19:49:32 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(b_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	lstaddback(b_list **list, b_list *new)
{
	b_list	*temp;
	
	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

b_list	*lstnew(int num)
{
	b_list	*new;
	
	new = malloc(sizeof(b_list));
	if (!new)
		return (NULL);
	new->num = num;
	new->next = NULL;
	return (new);
}

