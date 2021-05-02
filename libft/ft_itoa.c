/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:35:04 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/28 22:13:41 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(long a)
{
	int res;

	res = 0;
	while (a /= 10)
		res++;
	return (res);
}

long	ft_longabs(long a)
{
	long res;

	if (a < 0)
		res = (long)a * (-1);
	else
		res = (long)a;
	return (res);
}

char	*ft_itoa(long a)
{
	char	*res;
	long	tmp;
	int		strlen;

	if (a < -2147483648 || a > 2147483647)
		return (NULL);
	tmp = ft_longabs(a);
	strlen = 2 + ft_intlen(tmp);
	if ((res = (char*)malloc(strlen)) == NULL)
		return (NULL);
	res[strlen - 1] = '\0';
	while (--strlen)
	{
		res[strlen - 1] = tmp % 10 + 48;
		tmp = tmp / 10;
	}
	return (res);
}
