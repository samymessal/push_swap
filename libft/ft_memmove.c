/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:55:05 by smessal           #+#    #+#             */
/*   Updated: 2022/05/12 15:11:15 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*s_cpy;
	unsigned char	*d_cpy;

	s_cpy = (unsigned char *)src;
	d_cpy = (unsigned char *)dest;
	i = 0;
	if (d_cpy < s_cpy)
	{
		while (i < n)
		{
			d_cpy[i] = s_cpy[i];
			i++;
		}
	}
	else
	{
		while (n > i)
		{
			d_cpy[n - 1] = s_cpy[n - 1];
			n--;
		}
	}
	return (dest);
}
