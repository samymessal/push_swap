/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:15:38 by smessal           #+#    #+#             */
/*   Updated: 2022/06/25 19:52:03 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

b_list	*ft_table(int ac, char **arg)
{
	b_list	*a;
	b_list	*temp;
	int		i;
	
	i = 1;
	a = NULL;
	if (ac == 2)
	{
		arg = ft_split(arg[1], ' ');
		i = 0;
	}
	while(arg[i])
	{
		temp = lstnew(ft_atoi(arg[i]));
		lstaddback(&a, temp);
		i++;
	}
	return (a);
}

int	main(int ac, char **av)
{
	if (ac < 1)
		return (0);
	b_list *test = ft_table(ac, av);
	ft_sa(&test);
	while (test)
	{
		printf("%d\n", test->num);
		if (test->next == NULL)
			break ;
		test = test->next;
	}
	// test = test->next;
	// printf("%d", test->num);
	
	return (1);
}