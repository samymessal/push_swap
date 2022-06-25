/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:34:16 by smessal           #+#    #+#             */
/*   Updated: 2022/05/20 16:59:48 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*tab;

	if (count && ((count * size / count) != size))
		return (NULL);
	tab = malloc(count * size);
	if (!tab)
		return (NULL);
	ft_bzero((char *)tab, size * count);
	return ((char *)tab);
}
