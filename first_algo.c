/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_algo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 17:33:06 by smessal           #+#    #+#             */
/*   Updated: 2022/07/03 19:09:49 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move(b_list **a, b_list **b)
{
	b_list	*temp;
	int		val;
	int		index;

	temp = *a;
	val = ft_cost(a);
	index = ft_getindex(a, val);
	if (index > lstsize(*a)/2)
		while ((*a)->num != val)
			ft_rra(a);
	else
		while ((*a)->num != val)
			ft_ra(a);
	ft_pa(a, b);
	// if (val == ft_getmax(*b) && lstsize(*b) > 2)
	// 	ft_rb(b);
	ft_uptade_index(a);
}

int	ft_getindex(b_list **a, int val)
{
	b_list	*temp;

	temp = *a;
	while(temp)
	{
		temp = temp->next;
		if (temp->num == val)
			break;
		if (temp->next == NULL)
			break ;
	}
	return (temp->index);
}

int	ft_cost(b_list **a)
{
	int	min;
	int	max;
	int	index_max;
	int	index_min;
	int	mid;

	min = ft_getmin(*a);
	max = ft_getmax(*a);
	index_max = ft_getindex(a, max);
	index_min = ft_getindex(a, min);
	mid = lstsize(*a)/2;
	if (index_max > mid)
		index_max = lstsize(*a) - index_max;
	if (index_min > mid)
		index_min = lstsize(*a) - index_min;
	if (index_max > index_min)
		return (min);
	else
		return(max);
}

void	ft_loop(b_list **a, b_list **b)
{
	while ((*a))
	{
		ft_move(a, b);
		if ((*a)->next == NULL)
		{
			ft_pa(a, b);
			break;
		}
	}
}