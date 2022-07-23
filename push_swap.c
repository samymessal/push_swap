/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:15:38 by smessal           #+#    #+#             */
/*   Updated: 2022/07/23 17:55:07 by smessal          ###   ########.fr       */
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
		return (NULL);
	}
	ft_ind_final(&a);
	return (a);
}

int	main(int ac, char **av)
{
	t_stack	*test;
	t_stack	*test2;

	if (ac < 2)
		return (0);
	test = ft_table(ac, av);
	test2 = malloc(sizeof(t_stack));
	test2 = NULL;
	ft_ind_final(&test);
	ft_longsuit(&test);
	ft_ind_push(&test);
	ft_pushto_b(&test, &test2);
	//ft_costb(&test, &test2);
	ft_all(&test, &test2);
	// int len = 0;
	// int	count = 0;
	// if (lstsize(test) > lstsize(test2))
	// 	len = lstsize(test);
	// else
	// 	len = lstsize(test2);
	// printf("a\tfinal\tsuit\t\tb\tfinal\tcost\n\n");
	// while (count < len)
	// {
	// 	printf("%d\t%d\t%d\t\t", test->num, test->index, test->push_b);
	// 	if (test2)
	// 		printf("%d\t%d\t%d\n", test2->num, test2->index, test2->cost);
	// 	else
	// 		printf(" \n");
	// 	if (test->next)
	// 		test = test->next;
	// 	if (test2 && test2->next)
	// 		test2 = test2->next;
	// 	count++;
	// }
	return (0);
}
