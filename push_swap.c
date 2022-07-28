/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:15:38 by smessal           #+#    #+#             */
/*   Updated: 2022/07/28 12:05:32 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_table(int ac, char **arg)
{
	t_stack	*a;
	t_stack	*temp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	a = NULL;
	if (ac == 2)
	{
		arg = ft_split(arg[1], ' ');
		i = 0;
	}
	while (arg[i])
	{
		temp = lstnew(ft_atoi(arg[i++]), j++);
		lstaddback(&a, temp);
	}
	if (!ft_checkdup(&a) || !ft_check_num(ac, arg))
	{
		write(1, "Error\n", 6);
		return (ft_lstdel(a), NULL);
	}
	ft_ind_final(&a);
	return (a);
}

void	ft_start_500(t_stack **a, t_stack **b)
{
	if (!(*a))
		return ;
	ft_ind_final(a);
	ft_longsuit(a);
	ft_ind_push(a);
	ft_pushto_b(a, b);
	if (!(*b))
		return ;
	ft_all(a, b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	if (ac < 2)
		return (0);
	a = ft_table(ac, av);
	if (!a)
		return (0);
	b = NULL;
	if (lstsize(a) <= 3)
		ft_sort3(&a);
	else if (lstsize(a) <= 5 && lstsize(a) > 3)
		ft_sort5(&a, &b);
	else if (lstsize(a) > 5)
		ft_start_500(&a, &b);
	ft_lstdel(a);
	return (0);
}
