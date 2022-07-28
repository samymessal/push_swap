/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 15:19:33 by smessal           #+#    #+#             */
/*   Updated: 2022/07/27 17:20:27 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_getmax_suit(t_stack *a)
{
	t_stack	*temp;
	t_stack	*max;

	if (!a)
		return (NULL);
	temp = a;
	max = a;
	while (temp)
	{
		temp = temp->next;
		if (temp->suit > max->suit)
			max = temp;
		if (temp->next == NULL)
			break ;
	}
	return (max);
}

t_stack	*ft_getmin_cost(t_stack *b)
{
	t_stack	*temp;
	t_stack	*min;

	temp = b;
	min = temp;
	while (temp)
	{
		if (temp->cost < min->cost)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	ft_uptade_index(t_stack **a)
{
	int		i;
	t_stack	*temp;

	i = 0;
	temp = *a;
	while (temp)
	{
		temp->index = i;
		i++;
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
}

int	ft_issorted(t_stack **a)
{
	t_stack	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->next && temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_ind_final(t_stack **a)
{
	t_stack	*temp;
	t_stack	*temp2;
	int		ind_final;

	temp = *a;
	temp2 = NULL;
	while (temp)
	{
		ind_final = 0;
		temp2 = *a;
		while (temp2)
		{
			if (temp->num > temp2->num)
				ind_final++;
			temp2 = temp2->next;
		}
		temp->ind_final = ind_final;
		temp = temp->next;
	}
}
