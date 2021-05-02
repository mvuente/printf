/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		my_putstr(char *s, int charsprinted)
{
	int count;

	if (s == NULL)
		return (charsprinted);
	count = ft_strlen(s);
	charsprinted += count;
	while (count--)
	{
		write(1, s, 1);
		s++;
	}
	return (charsprinted);
}
