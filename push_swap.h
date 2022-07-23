/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:33:36 by smessal           #+#    #+#             */
/*   Updated: 2022/07/23 15:47:18 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"
# include <limits.h>
# include <unistd.h>

typedef struct a_list
{
	struct a_list	*next;
	int				num;
	int				index;
	int				ind_final;
	int				suit;
	int				push_b;
	int				cost;
}				t_stack;
t_stack	*ft_table(int ac, char **arg);
t_stack	*lstnew(int num, int index);
void	lstaddback(t_stack **list, t_stack *new);
int		lstsize(t_stack *lst);
void	ft_sa(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rb(t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rra(t_stack **a);
void	ft_rrb(t_stack **b);
t_stack	*ft_getmin(t_stack *a);
t_stack	*ft_getmax(t_stack *a);
t_stack	*ft_getmax_suit(t_stack *a);
void	ft_uptade_index(t_stack **a);
int		ft_check_num(int ac, char **av);
int		ft_checkdup(t_stack **a);
int		ft_issorted(t_stack **a);
void	ft_sort3(t_stack **a);
void	ft_sort5(t_stack **a, t_stack **b);
void	ft_ind_final(t_stack **a);
void	ft_longsuit(t_stack **a);
void	ft_ind_push(t_stack **a);
void	ft_pushto_b(t_stack **a, t_stack **b);
void	ft_costb(t_stack **a, t_stack **b);
t_stack	*ft_getmin_cost(t_stack *b);
void	ft_final_push(t_stack **a, t_stack **b);
void	ft_all(t_stack **a, t_stack **b);
t_stack	*ft_get_a(t_stack **a, t_stack **b, t_stack	*min);
t_stack	*ft_get_b(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);
void	ft_final_b(t_stack **a, t_stack **b, t_stack *min_a, t_stack *min_b);
int		ft_costb_1(t_stack **a, t_stack **b, t_stack *temp_a, t_stack *temp_b);

#endif
