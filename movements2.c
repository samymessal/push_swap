/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 22:55:59 by smessal           #+#    #+#             */
/*   Updated: 2022/07/08 14:34:58 by smessal          ###   ########.fr       */
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
	write(1, "ra\n", 3);
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
	write(1, "rb\n", 3);
}

void	ft_rr(b_list **a, b_list **b)
{
	b_list	*temp;
	b_list	*temp2;
	b_list	*temp3;
	b_list	*temp4;
	
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
	write(1, "rra\n", 4);
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
	write(1, "rrb\n", 4);
}

void	ft_rrr(b_list **a, b_list **b)
{
	b_list	*temp;
	b_list	*temp2;
	b_list	*temp3;
	b_list	*temp4;
	
	temp = *a;
	temp2 = *a;
	while (temp->next)
		temp = temp->next;
	while(temp2->next->next)
		temp2 = temp2->next;
	temp->next = *a;
	*a = temp;
	temp2->next = NULL;
	temp3 = *b;
	temp4 = *b;
	while (temp3->next)
		temp3 = temp3->next;
	while(temp4->next->next)
		temp4 = temp4->next;
	temp3->next = *b;
	*b = temp3;
	temp4->next = NULL;
	write(1, "rrr\n", 4);
}