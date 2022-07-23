/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:55:59 by smessal           #+#    #+#             */
/*   Updated: 2022/07/23 15:41:13 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *a;
	while (temp->next)
		temp = temp->next;
	temp->next = *a;
	temp2 = *a;
	*a = (*a)->next;
	temp2->next = NULL;
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (lstsize(*b) < 2)
		return ;
	temp = *b;
	while (temp->next)
		temp = temp->next;
	temp->next = *b;
	temp2 = *b;
	*b = (*b)->next;
	temp2->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;
	t_stack	*temp3;
	t_stack	*temp4;

	temp = *a;
	while (temp->next)
		temp = temp->next;
	temp->next = *a;
	temp2 = *a;
	*a = (*a)->next;
	temp2->next = NULL;
	temp3 = *b;
	while (temp3->next)
		temp3 = temp3->next;
	temp3->next = *b;
	temp4 = *b;
	*b = (*b)->next;
	temp4->next = NULL;
	write(1, "rr\n", 3);
}

void	ft_rra(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;

	temp = *a;
	temp2 = *a;
	while (temp->next)
		temp = temp->next;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp->next = *a;
	*a = temp;
	temp2->next = NULL;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (lstsize(*b) < 2)
		return ;
	temp = *b;
	temp2 = *b;
	while (temp->next)
		temp = temp->next;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp->next = *b;
	*b = temp;
	temp2->next = NULL;
	write(1, "rrb\n", 4);
}
