/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:27:20 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/30 15:46:34 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_bool	ft_numeric_digits(t_flags *flags)
{
	if (!flags->dot)
	{
		if (flags->strlen > flags->max_width)
			flags->max_width = flags->strlen;
		return (TRUE);
	}
	return (FALSE);
}

static t_bool	ft_except_noprec_zero(t_flags *flags)
{
	if (!flags->precision && *flags->str == '0')
	{
		*flags->str = '\0';
		flags->max_width = 0;
		flags->precision = 0;
		flags->strlen = 0;
		if (flags->digits && flags->digits > flags->max_width)
			flags->extra_right_padding = flags->digits - flags->max_width;
		return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_numeric_precision(t_flags *flags)
{
	size_t	abs_strlen;

	if (flags->dot)
	{
		flags->zero = TRUE;
		flags->dash = FALSE;
		if (ft_except_noprec_zero(flags))
			return (TRUE);
		if (*flags->str == '-')
			abs_strlen = flags->strlen - 1;
		else
			abs_strlen = flags->strlen;
		if (flags->precision > abs_strlen)
			abs_strlen = flags->precision;
		flags->strlen = abs_strlen;
		if (flags->precision < flags->strlen)
			flags->precision = flags->strlen;
		if (*flags->str == '-')
		{
			flags->max_width = abs_strlen + 1;
			flags->precision++;
		}
		else
			flags->max_width = abs_strlen;
		if (flags->digits && flags->digits > flags->max_width)
			flags->extra_right_padding = flags->digits - flags->max_width;
	}
	return (FALSE);
}
