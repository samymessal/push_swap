/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 20:14:01 by smessal           #+#    #+#             */
/*   Updated: 2022/05/12 12:47:03 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		ls1;
	int		ls2;
	int		i;
	int		j;
	char	*joined;

	i = 0;
	j = 0;
	ls1 = ft_strlen(s1);
	ls2 = ft_strlen(s2);
	joined = malloc(sizeof(char) * (ls1 + ls2 + 1));
	if (!joined)
		return (NULL);
	while (s1[i])
		joined[j++] = s1[i++];
	i = 0;
	while (s2[i])
		joined[j++] = s2[i++];
	joined[j] = '\0';
	return (joined);
}
/*
int	main(void)
{
	char	*test1;
	char	*test2;

	test1 = "lolilo ";
	test2 = "";
	printf("%s", ft_strjoin(test1, test2));
}
*/
