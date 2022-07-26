/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:40 by smessal           #+#    #+#             */
/*   Updated: 2022/07/25 22:38:35 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_stack *lst)
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

void	lstaddback(t_stack **list, t_stack *new)
{
	t_stack	*temp;

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

t_stack	*lstnew(int num, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = index;
	new->next = NULL;
	return (new);
}

t_stack	*ft_getmin(t_stack *a)
{
	t_stack	*temp;
	t_stack	*min;

	temp = a;
	min = temp;
	while (temp)
	{
		temp = temp->next;
		if (temp->num < min->num)
			min = temp;
		if (temp->next == NULL)
			break ;
	}
	return (min);
}

t_stack	*ft_getmax(t_stack *a)
{
	t_stack	*temp;
	t_stack	*max;

	temp = a;
	max = temp;
	while (temp)
	{
		temp = temp->next;
		if (temp->num > max->num)
			max = temp;
		if (temp->next == NULL)
			break ;
	}
	return (max);
}
