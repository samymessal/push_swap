/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:22:52 by smessal           #+#    #+#             */
/*   Updated: 2022/05/10 19:37:47 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s2;
	size_t			i;

	s2 = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (s2[i] == (unsigned char)c)
			return (&s2[i]);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char *test1 = ft_memchr("louidje", 'd', 0);
	char *test2 = memchr("louidje", 'd', 0);
	printf("%s\n%s", test1, test2);
}
*/
