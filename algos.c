/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 12:57:40 by smessal           #+#    #+#             */
/*   Updated: 2022/07/07 17:03:43 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort3(b_list **a)
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

void	ft_sort5(b_list **a, b_list **b)
{
	b_list	*temp;

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