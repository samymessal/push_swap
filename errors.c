/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 20:06:21 by smessal           #+#    #+#             */
/*   Updated: 2022/07/03 21:16:44 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_check_num(char **av, int i)
{
    int j;

    j = 0;
    while(av[i])
    {
        if (ft_strlen(av[i]) > 11 || ft_atoi(av[i]) > INT_MAX || ft_atoi(av[i]) < INT_MIN)
            return (0);
        j = 0;
        if (av[i][j] == '-')
            j++;
        while(av[i][j])
        {
            if (av[i][j] < '0' || av[i][j] > '9')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int ft_checkdup(b_list **a)
{
    b_list  *temp;
    b_list  *temp2;
    int     num;
    
    temp = *a;
    while (temp)
    {
        num = temp->num;
        temp2 = temp->next;
        while (temp2)
        {
            if (temp2->num == num)
                return (0);
            if (temp2->next == NULL)
                break ; 
            temp2 = temp2->next;
        }
        if (temp->next == NULL)
                break ; 
        temp = temp->next;
    }
    return (1);
}