/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neg_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvuente <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:31:08 by mvuente           #+#    #+#             */
/*   Updated: 2020/05/27 15:33:42 by mvuente          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

t_collect	*neg_precision(t_collect *stock)
{
	if (stock->prec_prcnt_flag == 1)
	{
		stock->width = -stock->precision;
		stock->m_flag = 1;
	}
	return (stock);
}
