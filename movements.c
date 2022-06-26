/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:48:43 by smessal           #+#    #+#             */
/*   Updated: 2022/06/26 17:29:16 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_sa(b_list **a)
{
	b_list	*temp;
	b_list	*temp2;

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
}

void	ft_sb(b_list **b)
{
	b_list	*temp;
	b_list	*temp2;

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

void	ft_ss(b_list **a, b_list **b)
{
	ft_sa(a);
	ft_sb(b);
}

void	ft_pa(b_list **a, b_list **b)
{
	b_list	*temp;
	b_list	*temp2;

	temp = *b;
	*b = (*b)->next;
	temp2 = *a;
	temp->next = temp2;
	*a = temp;
}

void	ft_pb(b_list **b, b_list **a)
{
	b_list	*temp;
	b_list	*temp2;

	temp = *b;
	*b = (*b)->next;
	temp2 = *a;
	temp->next = temp2;
	*a = temp;
}

void	ft_ra(b_list **a)
{
	b_list	*temp;
	b_list	*temp2;
	
	temp = *a;
	while (temp->next)
		temp = temp->next;
	temp->next = *a;
	temp2 = *a;
	*a = (*a)->next;
	temp2->next = NULL;
}

void	ft_rb(b_list **b)
{
	b_list	*temp;
	b_list	*temp2;
	
	temp = *b;
	while (temp->next)
		temp = temp->next;
	temp->next = *b;
	temp2 = *b;
	*b = (*b)->next;
	temp2->next = NULL;
}

void	ft_rr(b_list **a, b_list **b)
{
	ft_ra(a);
	ft_rb(b);
}

void	ft_rra(b_list **a)
{
	b_list	*temp;
	b_list	*temp2;

	temp = *a;
	temp2 = *a;
	while (temp->next)
		temp = temp->next;
	while(temp2->next->next)
		temp2 = temp2->next;
	temp->next = *a;
	*a = temp;
	temp2->next = NULL;
}

void	ft_rrb(b_list **b)
{
	b_list	*temp;
	b_list	*temp2;

	temp = *b;
	temp2 = *b;
	while (temp->next)
		temp = temp->next;
	while(temp2->next->next)
		temp2 = temp2->next;
	temp->next = *b;
	*b = temp;
	temp2->next = NULL;
}

void	ft_rrr(b_list **a, b_list **b)
{
	ft_rra(a);
	ft_rrb(b);
}