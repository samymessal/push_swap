/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:40 by smessal           #+#    #+#             */
/*   Updated: 2022/07/07 17:56:35 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lstsize(b_list *lst)
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

void	lstaddback(b_list **list, b_list *new)
{
	b_list	*temp;
	
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

b_list	*lstnew(int num, int index)
{
	b_list	*new;
	
	new = malloc(sizeof(b_list));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = index;
	new->next = NULL;
	return (new);
}

int	ft_getmin(b_list *a)
{
	b_list	*temp;
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

int	ft_getmax(b_list *a)
{
	b_list	*temp;
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

void	ft_uptade_index(b_list **a)
{
	int	i;
	b_list	*temp;

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

int	ft_issorted(b_list **a)
{
	b_list	*temp;

	temp = *a;
	while (temp)
	{
		if (temp->next && temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_ind_final(b_list **a)
{
	b_list	*temp;
	b_list	*temp2;
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