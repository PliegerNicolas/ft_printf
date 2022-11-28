/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_flagger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:12:56 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/28 11:12:22 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_int_flagger(t_flags *flags_list, size_t strlen)
{
	size_t		old_precision;

	if (flags_list->dot)
	{
		if (flags_list->str[0] == '0' && !flags_list->precision)
			return ;
		if (flags_list->precision)
		{
			flags_list->zero = TRUE;
			flags_list->dash = FALSE;
		}
		else
		{
			flags_list->zero = FALSE;
			flags_list->dash = TRUE;
		}
		old_precision = flags_list->precision;
		if (flags_list->precision < strlen)
			flags_list->precision = strlen;
		flags_list->width = flags_list->precision;
		if (flags_list->str[0] == '-' && old_precision >= strlen)
			flags_list->width++;
	}
}
