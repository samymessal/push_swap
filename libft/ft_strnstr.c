/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 19:40:55 by smessal           #+#    #+#             */
/*   Updated: 2022/05/16 17:25:27 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	while (str[i] && i < n)
	{
		j = 0;
		if (str[i] == to_find[j])
		{
			if (ft_strncmp(str + i, to_find + j, ft_strlen(to_find)) == 0
				&& i + ft_strlen(to_find) <= n)
				return ((char *)str + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
