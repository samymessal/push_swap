/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:48:43 by smessal           #+#    #+#             */
/*   Updated: 2022/07/28 12:02:48 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (lstsize(*a) < 2)
		return ;
	temp = *a;
	if (!temp)
		return ;
	temp = temp->next;
	temp2 = *a;
	temp2->next = temp->next;
	*a = temp;
	(*a)->next = temp2;
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (lstsize(*b) < 2)
		return ;
	temp = *b;
	if (!temp)
		return ;
	temp = temp->next;
	temp2 = *b;
	temp2->next = temp->next;
	*b = temp;
	(*b)->next = temp2;
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*b == NULL)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (*a == NULL)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}
