/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:33:36 by smessal           #+#    #+#             */
/*   Updated: 2022/07/03 17:00:54 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct	a_list
{
	struct a_list *next;
	int	num;
	int	index;
}				b_list;
b_list	*ft_table(int ac, char **arg);
b_list	*lstnew(int num, int index);
void	lstaddback(b_list **list, b_list *new);
int	lstsize(b_list *lst);
void	ft_sa(b_list **a);
void	ft_sb(b_list **b);
void	ft_ss(b_list **a, b_list **b);
void	ft_pa(b_list **a, b_list **b);
void	ft_pb(b_list **b, b_list **a);
void	ft_ra(b_list **a);
void	ft_rb(b_list **b);
void	ft_rr(b_list **a, b_list **b);
void	ft_rra(b_list **a);
void	ft_rrb(b_list **b);
void	ft_move(b_list **a, b_list **b);
int		ft_getmin(b_list *a);
int		ft_getmax(b_list *a);
void	ft_loop(b_list **a, b_list **b);
void	ft_uptade_index(b_list **a);
void	ft_first_push(b_list **a, b_list **b);
void	ft_algo(b_list **a, b_list **b);
int		ft_cost(b_list **a);
int		ft_getindex(b_list **a, int val);



#endif
