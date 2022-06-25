/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 22:02:54 by smessal           #+#    #+#             */
/*   Updated: 2022/05/12 12:46:23 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int				i;
	long long int	num;

	i = 0;
	if (n == 0)
		return (1);
	num = n;
	if (num < 0)
	{
		num *= -1;
		i = 1;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*num;
	int				len;
	long long int	long_n;

	len = ft_numlen(n);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	long_n = n;
	if (long_n < 0)
	{
		long_n *= -1;
		num[0] = '-';
	}
	num[len] = '\0';
	while (long_n > 9)
	{
		num[len - 1] = (long_n % 10) + '0';
		long_n /= 10;
		len--;
	}
	num[len - 1] = long_n + '0';
	return (num);
}
/*
int	main(void)
{
	printf("%s", ft_itoa(-7));
}
*/
