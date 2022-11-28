/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_flagger.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:12:56 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/28 12:30:56 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_int_flagger(t_flags *flags_list, size_t strlen)
{
	size_t		old_precision;
	size_t		old_width;

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
		old_width = flags_list->width;
		if (flags_list->precision < strlen)
			flags_list->precision = strlen;
		if (flags_list->precision && flags_list->digits && old_width > flags_list->precision)
			flags_list->extra_right_padding = old_width - flags_list->precision;
		else
			flags_list->extra_right_padding = 0;
		flags_list->width = flags_list->precision;
		if (flags_list->str[0] == '-' && old_precision >= strlen)
			flags_list->width++;
	}
}
