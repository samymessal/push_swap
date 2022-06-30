/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:40 by smessal           #+#    #+#             */
/*   Updated: 2022/06/30 13:15:16 by smessal          ###   ########.fr       */
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

b_list	*lstnew(int num, int index)
{
	b_list	*new;
	
	new = malloc(sizeof(b_list));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = index;
	new->next = NULL;
	return (new);
}

int	ft_getmin(b_list *a)
{
	b_list	*temp;
	int	min;

	temp = a;
	min = temp->num;
	while(temp)
	{
		temp = temp->next;
		if (temp->num < min)
			min = temp->num;
		if (temp->next == NULL)
			break ; 
	}
	return (min);
}

void	ft_move(b_list **a, b_list **b)
{
	b_list	*temp;
	int		min;
	int		index;

	temp = *a;
	min = ft_getmin(*a);
	while(temp)
	{
		temp = temp->next;
		if (temp->num == min)
			break;
		if (temp->next == NULL)
			break ;
	}
	index = temp->index;
	if (index > lstsize(*a)/2)
		while ((*a)->num != min)
			ft_rra(a);
	else
		while ((*a)->num != min)
			ft_ra(a);
	ft_pa(a, b);
}

void	ft_loop(b_list **a, b_list **b)
{
	while ((*a))
	{
		ft_move(a, b);
		if ((*a)->next == NULL)
			ft_pa(a, b);
	}
}
/*
Obtain min
check index with length of list
decide if ra or rra
pa
adjust indexes with variable that stocks number of calls to ra/rra - 1 because of pa
repeat
pb until b empty
*/