/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 17:15:38 by smessal           #+#    #+#             */
/*   Updated: 2022/06/28 23:01:58 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

b_list	*ft_table(int ac, char **arg)
{
	b_list	*a;
	b_list	*temp;
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
	while(arg[i])
	{
		temp = lstnew(ft_atoi(arg[i]), j);
		lstaddback(&a, temp);
		i++;
		j++;
	}
	return (a);
}

int	main(int ac, char **av)
{
	if (ac < 1)
		return (0);
	b_list *test = ft_table(ac, av);
	b_list *test2 = malloc(sizeof(b_list));

	test2 = NULL;
	ft_pa(&test, &test2);
	ft_pa(&test, &test2);
	ft_pb(&test2, &test);
	printf("a\t\tb\n\n");
	while (test || test2)
	{
		printf("%d\t\t%d\n", test->num, test2->num);
		if (test->next == NULL)
			break ;
		test = test->next;
		if(test2->next)
			test2 = test2->next;
	}
	// printf("\n");
	
	// while (test2)
	// {
	// 	printf("%d\n", test2->num);
	// 	if (test2->next == NULL)
	// 		break ;
	// 	test2 = test2->next;
	// }
	// test = test->next;
	// printf("%d", test->num);
	
	return (1);
}