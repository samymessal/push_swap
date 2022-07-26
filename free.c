/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:40:41 by smessal           #+#    #+#             */
/*   Updated: 2022/07/25 23:35:40 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_lstdel(t_stack *lst)
{
    t_stack *temp;

    temp = lst;
    while (temp)
    {
        lst = temp;
        temp = temp->next;
        lst->cost = 0;
        lst->ind_final = 0;
        lst->index = 0;
        lst->num = 0;
        lst->push_b = 0;
        lst->suit = 0;
        free(lst);
    }
}
