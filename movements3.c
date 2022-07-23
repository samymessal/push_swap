/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:29:10 by smessal           #+#    #+#             */
/*   Updated: 2022/07/23 15:30:04 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*temp2;
	t_stack	*temp3;
	t_stack	*temp4;

	temp = *a;
	temp2 = *a;
	while (temp->next)
		temp = temp->next;
	while (temp2->next->next)
		temp2 = temp2->next;
	temp->next = *a;
	*a = temp;
	temp2->next = NULL;
	temp3 = *b;
	temp4 = *b;
	while (temp3->next)
		temp3 = temp3->next;
	while (temp4->next->next)
		temp4 = temp4->next;
	temp3->next = *b;
	*b = temp3;
	temp4->next = NULL;
	write(1, "rrr\n", 4);
}
