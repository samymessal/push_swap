/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 17:31:15 by smessal           #+#    #+#             */
/*   Updated: 2022/05/12 15:43:02 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	if (!dest && !src)
		return (NULL);
	i = 0;
	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
/*
Correcte mais comment tester
int	main(void)
{
	char *src = "abcdef";
	char *dest = "123def";
	char *result;
	result = memcpy(dest, src, 3);
	printf("%s", dest);
}
*/
