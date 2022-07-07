/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:55:59 by smessal           #+#    #+#             */
/*   Updated: 2022/07/07 15:20:53 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	printf("ra\n");
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
	printf("rra\n");
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