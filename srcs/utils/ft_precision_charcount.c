/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_charcount.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:15:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/18 17:52:28 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_precision_charcount(const double nb, const size_t precision)
{
	size_t			char_count;
	long double		n;

	char_count = 0;
	if (nb < 0 || ft_isnegativezero(nb))
	{
		char_count++;
		n = -nb;
	}
	else
		n = nb;
	if (n < 1)
		return (++char_count + precision + 1);
	while (n >= 1)
	{
		n /= 10;
		char_count++;
	}
	if (precision > 0)
		char_count++;
	return (char_count + precision);
}
