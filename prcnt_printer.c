/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prcnt_printer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	prcnt_printer(const char **format)
{
	int count;
	int i;

	count = prcnt_counter(*format);
	i = count / 2;
	while (i--)
		write(1, "%", 1);
	*format = *format + 1 + count / 2;
	return (count / 2);
}
