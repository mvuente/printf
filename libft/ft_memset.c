/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:49 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 16:43:57 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*res;
	unsigned char	var;
	int				i;

	i = 0;
	res = (unsigned char *)s;
	var = (unsigned char)c;
	while (n--)
	{
		res[i] = var;
		i++;
	}
	return (s);
}
