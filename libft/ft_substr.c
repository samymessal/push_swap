/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:29:14 by smessal           #+#    #+#             */
/*   Updated: 2022/05/17 16:09:09 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sublen(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (str && str[i] && i < start)
		i++;
	j = 0;
	while (str && str[i] && j < len)
	{
		i++;
		j++;
	}
	return (j);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sub;

	if (!s)
		return (NULL);
	len = ft_sublen(s, start, len);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
/*
int	main(void)
{
	printf("%s", ft_substr("123456789999", 3, 0));
}
*/
