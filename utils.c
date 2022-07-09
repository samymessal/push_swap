/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:40 by smessal           #+#    #+#             */
/*   Updated: 2022/07/09 18:48:08 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}

void	lstaddback(t_stack **list, t_stack *new)
{
	t_stack	*temp;
	
	if (!new)
		return ;
	if (!*list)
	{
		*list = new;
		return ;
	}
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

t_stack	*lstnew(int num, int index)
{
	t_stack	*new;
	
	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = index;
	new->next = NULL;
	return (new);
}

int	ft_getmin(t_stack *a)
{
	t_stack	*temp;
	int	min;

	temp = a;
	min = temp->num;
	while(temp)
	{
		temp = temp->next;
		if (temp->num < min)
			min = temp->num;
		if (temp->next == NULL)
			break ; 
	}
	return (min);
}

int	ft_getmax(t_stack *a)
{
	t_stack	*temp;
	int	max;

	temp = a;
	max = temp->num;
	while(temp)
	{
		temp = temp->next;
		if (temp->num > max)
			max = temp->num;
		if (temp->next == NULL)
			break ; 
	}
	return (max);	
}

t_stack	*ft_getmax_suit(t_stack *a)
{
	t_stack	*temp;
	t_stack	*max;

	temp = a;
	max = a;
	while(temp)
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
	while(temp)
	{
		temp = temp->next;
		if (temp->cost < min->cost)
			min = temp;
		if (temp->next == NULL)
			break ; 
	}
	return (min);
}

void	ft_uptade_index(t_stack **a)
{
	int	i;
	t_stack	*temp;

	i = 0;
	temp = *a;
	while (temp)
	{
		temp->index = i;
		i++;
		if (temp->next == NULL)
			break;
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

void	ft_coststack(t_stack *temp_a, t_stack *temp_b, t_stack **a, t_stack **b)
{
	if (temp_a->index > lstsize(*a) / 2)
	{
		temp_b->cost = lstsize(*a) - temp_a->index;
		if (temp_b->index > lstsize(*b) / 2)
			temp_b->cost += lstsize(*b) - temp_b->index;
		else
			temp_b->cost += temp_b->index;
	}
	else
	{
		temp_b->cost = temp_a->index;
		if (temp_b->index > lstsize(*b) / 2)
			temp_b->cost += lstsize(*b) - temp_b->index;
		else
			temp_b->cost += temp_b->index;
	}
}

void	ft_costb(t_stack **a, t_stack **b)
{
	t_stack	*temp_a;
	t_stack	*temp_b;
	int		count;

	ft_uptade_index(a);
	ft_uptade_index(b);
	temp_b = *b;
	count = 0;
	while (temp_b)
	{
		temp_a = *a;
		while (temp_a)
		{
			if (temp_a->ind_final > temp_b->ind_final)
			{
				ft_coststack(temp_a, temp_b, a, b);
				break;
			}
			temp_a = temp_a->next;
		}
		temp_b = temp_b->next;
	}
}

/*
Obtain min
check index with length of list
decide if ra or rra
pa
adjust indexes with variable that stocks number of calls to ra/rra - 1 because of pa
repeat
pb until b empty
*/

// idea 2

/*
Put half of the list in b
Calculate min max of a & b
if (min b < min a)
	ft_move(a)
if (min b > min a)
	ft_move(b)
*/