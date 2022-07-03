/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:48:43 by smessal           #+#    #+#             */
/*   Updated: 2022/07/03 19:07:05 by smessal          ###   ########.fr       */
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

	temp = *a;
	*a = (*a)->next;
	temp2 = *b;
	temp->next = temp2;
	*b = temp;
	//printf("pa\n");
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