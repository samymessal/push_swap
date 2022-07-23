/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:14:57 by smessal           #+#    #+#             */
/*   Updated: 2022/07/23 15:37:27 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_get_b(t_stack **a, t_stack **b)
{
	t_stack	*min;

	if (lstsize(*b) > 1)
	{
		ft_costb(a, b);
		min = ft_getmin_cost(*b);
	}
	else
		min = *b;
	return (min);
}

t_stack	*ft_get_a(t_stack **a, t_stack **b, t_stack	*min)
{
	t_stack	*temp;

	if (min->ind_final < ft_getmin(*a)->ind_final)
		temp = ft_getmin(*a);
	else if (min->ind_final > ft_getmax(*a)->ind_final)
		temp = ft_getmax(*a);
	else
	{
		temp = *a;
		while (temp)
		{
			if (temp->next && temp->ind_final < min->ind_final
				&& temp->next->ind_final > min->ind_final)
				break ;
			else if (!temp->next && temp->ind_final < min->ind_final)
			{
				if ((*a)->ind_final > temp->ind_final)
					break ;
			}
			temp = temp->next;
		}
	}
	return (temp);
}

void	ft_final_b(t_stack **a, t_stack **b, t_stack *min_a, t_stack *min_b)
{
	while ((*b)->num != min_b->num)
	{
		if (min_b->index > lstsize(*b) / 2 && min_a->index > lstsize(*a) / 2
			&& (*a)->num != min_a->num)
			ft_rrr(a, b);
		else if (min_b->index < lstsize(*b) / 2
			&& min_a->index < lstsize(*a) / 2 && (*a)->num != min_a->num)
			ft_rr(a, b);
		else if (min_b->index > lstsize(*b) / 2)
			ft_rrb(b);
		else if (min_b->index <= lstsize(*b) / 2)
			ft_rb(b);
	}
}

void	ft_final_push(t_stack **a, t_stack **b)
{
	t_stack	*min_b;
	t_stack	*min_a;

	min_b = ft_get_b(a, b);
	min_a = ft_get_a(a, b, min_b);
	ft_uptade_index(a);
	ft_uptade_index(b);
	ft_final_b(a, b, min_a, min_b);
	while ((*a)->num != min_a->num)
	{
		if (min_a->index > lstsize(*a) / 2)
			ft_rra(a);
		else
			ft_ra(a);
	}
	if (min_b->num > min_a->num)
		ft_ra(a);
	ft_pa(a, b);
}

void	ft_all(t_stack **a, t_stack **b)
{
	t_stack	*min;

	while (*b)
		ft_final_push(a, b);
	min = ft_getmin(*a);
	while ((*a)->num != min->num)
	{
		if (min->index > lstsize(*a) / 2)
			ft_rra(a);
		else
			ft_ra(a);
	}
}
