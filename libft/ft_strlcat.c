/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 16:24:13 by smessal           #+#    #+#             */
/*   Updated: 2022/05/12 16:38:32 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size == 0 || dst_len >= size)
		return (src_len + size);
	i = 0;
	while (src[i] && (i < size - dst_len - 1))
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	dest[dst_len + i] = '\0';
	return (dst_len + src_len);
}

/*
int	main()
{
	char dest[20] = "123456789";
	char src[] = "1234";
	printf("%zu\n", ft_strlcat(dest, src, 2));
}
*/
