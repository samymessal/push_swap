/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:33:36 by smessal           #+#    #+#             */
/*   Updated: 2022/06/25 22:04:50 by smessal          ###   ########.fr       */
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
}				b_list;
b_list	*ft_table(int ac, char **arg);
b_list	*lstnew(int num);
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

#endif
