/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:23:43 by smessal           #+#    #+#             */
/*   Updated: 2022/05/16 18:53:28 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_inset(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_char_rm(char const *s1, char const *set)
{
	int	i;
	int	count;
	int	len;

	i = 0;
	count = 0;
	len = ft_strlen(s1) - 1;
	while (s1[i] && ft_inset(set, s1[i]))
	{
		count++;
		i++;
	}
	while (s1[len] && ft_inset(set, s1[len]))
	{
		count++;
		len--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len_s1;
	int		i;
	int		j;
	char	*trimed;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1) - ft_char_rm(s1, set);
	if (len_s1 < 0)
		len_s1 = 0;
	trimed = malloc(sizeof(char) * (len_s1 + 1));
	if (!trimed)
		return (NULL);
	while (s1[i] && ft_inset(set, s1[i]))
		i++;
	while (j < len_s1)
	{
		trimed[j] = s1[i];
		i++;
		j++;
	}
	trimed[j] = '\0';
	return (trimed);
}
/*
int	main(void)
{
	char	*test1 = "   xxx   xxx";
	char	*set = " x";
	printf("%s", ft_strtrim(test1, set));
}
*/
