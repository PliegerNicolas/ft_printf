/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:12:36 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/17 17:26:32 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

size_t	ft_charcount(long int nb)
{
	size_t	char_count;

	char_count = 0;
	if (nb < 0)
		char_count++;
	if (nb == 0)
		return (++char_count);
	while (nb >= 1 || nb < 0)
	{
		nb /= 10;
		char_count++;
	}
	return (char_count);
}
