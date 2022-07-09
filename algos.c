/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:57:40 by smessal           #+#    #+#             */
/*   Updated: 2022/07/09 18:54:13 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(t_stack **a)
{
	while (!ft_issorted(a))
	{
		if ((*a)->num == ft_getmax(*a))
			ft_ra(a);
		else if ((*a)->next->num == ft_getmax(*a))
			ft_rra(a);
		else if ((*a)->next->next->num == ft_getmax(*a))
			ft_sa(a);
	}
}

void	ft_sort5(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	temp = *a;
	while (temp && lstsize(*a) > 3)
	{
		if (temp->num == ft_getmin(*a))
		{
			while ((*a)->num != ft_getmin(*a))
			{
				if (temp->index > lstsize(*a) / 2)
					ft_rra(a);
				else
					ft_ra(a);
			}
			ft_pb(a, b);
			ft_uptade_index(a);
			temp = *a;
		}
		temp = temp->next;
	}
	ft_sort3(a);
	ft_pa(a, b);
	ft_pa(a, b);
}

void	ft_longsuit(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		suit;
	int		stock;
	int		count;
	
	temp = *a;
	while (temp)
	{
		temp2 = temp;
		suit = 0;
		stock = temp2->num;
		count = 0;
		while (count++ < lstsize(*a))
		{
			if (temp2->next && stock < temp2->next->num)
			{
				temp->suit++;
				stock = temp2->next->num;
			}
			temp2 = temp2->next;
			if (!temp2)
				temp2 = *a;
		}
		temp = temp->next;
	}
}

void	ft_ind_push(t_stack **a)
{
	t_stack	*max;
	t_stack	*stock;
	int		count;

	max = ft_getmax_suit(*a);
	max->push_b = 1;
	stock = max;
	count = 0;
	while (count++ < lstsize(*a))
	{
		if (max && stock->num <= max->num)
		{
			max->push_b = 1;
			stock = max;
		}
		else
			max->push_b = 0;
		max = max->next;
		if (!max)
			max = *a;
	}
}

void	ft_pushto_b(t_stack **a, t_stack **b)
{
	int	count;
	int	size;
	
	size = lstsize(*a);
	count = 0;
	while (count < size)
	{
		if ((*a)->push_b == 0)
			ft_pb(a, b);
		else
			ft_ra(a);
		count++;
	}
}

void	ft_final_push(t_stack **a, t_stack **b)
{
	t_stack	*min;
	t_stack	*temp;
	//Ajouter les mouvements de stack A
	if (lstsize(*b) > 1)
	{
		ft_uptade_index(b);
		ft_uptade_index(a);
		min = ft_getmin_cost(*b);
		temp = *b;
		while (temp->num != min->num)
		{
			if (min->index > lstsize(*b) / 2)
				ft_rrb(b);
			else
				ft_rb(b);
		}
	}
	ft_pa(a, b);
}

void	ft_all(t_stack **a, t_stack **b)
{
	while (*b)
	{
		ft_final_push(a, b);
	}
}