/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:21:01 by smessal           #+#    #+#             */
/*   Updated: 2022/07/27 16:15:04 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	ft_adj_cost(t_stack *temp_a, t_stack *temp_b, t_stack **a, t_stack **b)
{
	if (temp_b->index > lstsize(*b) / 2 && temp_a->index > lstsize(*a) / 2)
	{
		if (temp_b->index >= temp_a->index)
			temp_b->cost -= lstsize(*a) - temp_b->index;
		else if (temp_b->index < temp_a->index)
			temp_b->cost -= lstsize(*b) - temp_a->index;
	}
	else if (temp_b->index <= lstsize(*b) / 2 && temp_a->index <= lstsize(*a) / 2)
	{
		if (temp_b->index >= temp_a->index)
			temp_b->cost -= temp_a->index;
		else if (temp_b->index < temp_a->index)
			temp_b->cost -= temp_b->index;
	}
}
*/
void	ft_coststack(t_stack *temp_a, t_stack *temp_b, t_stack **a, t_stack **b)
{
	if (temp_a->index > lstsize(*a) / 2)
	{
		temp_b->cost = lstsize(*a) - temp_a->index;
		if (temp_b->index > lstsize(*b) / 2)
			temp_b->cost += lstsize(*b) - temp_b->index;
		else
			temp_b->cost += temp_b->index;
	}
	else
	{
		temp_b->cost = temp_a->index;
		if (temp_b->index > lstsize(*b) / 2)
			temp_b->cost += lstsize(*b) - temp_b->index;
		else
			temp_b->cost += temp_b->index;
	}
}

int	ft_costb_1(t_stack **a, t_stack **b, t_stack *temp_a, t_stack *temp_b)
{
	if (temp_b->num > ft_getmax(*a)->num)
	{
		ft_coststack(temp_a, temp_b, a, b);
		return (0);
	}
	else if (temp_b->num < ft_getmin(*a)->num)
	{
		ft_coststack(temp_a, temp_b, a, b);
		return (0);
	}
	else if (temp_a->next && temp_a->ind_final < temp_b->ind_final
		&& temp_a->next->ind_final > temp_b->ind_final)
	{
		ft_coststack(temp_a, temp_b, a, b);
		return (0);
	}
	else if (!temp_a->next && temp_a->ind_final < temp_b->ind_final)
	{
		if ((*a)->ind_final > temp_b->ind_final)
		{
			ft_coststack(*a, temp_b, a, b);
			return (0);
		}
	}
	return (1);
}

void	ft_costb(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;

	ft_uptade_index(a);
	ft_uptade_index(b);
	temp_b = *b;
	while (temp_b)
	{
		temp_a = *a;
		while (temp_a)
		{
			if (!ft_costb_1(a, b, temp_a, temp_b))
				break ;
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}
