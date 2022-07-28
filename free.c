/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:40:41 by smessal           #+#    #+#             */
/*   Updated: 2022/07/28 13:54:25 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdel(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	while (temp)
	{
		lst = temp;
		temp = temp->next;
		free(lst);
	}
}

void	ft_free_arg(int ac, char **arg)
{
	int	i;

	if (ac != 2)
		return ;
	i = 0;
	while (arg[i])
	{
		free(arg[i]);
		i++;
	}
	free(arg);
}
