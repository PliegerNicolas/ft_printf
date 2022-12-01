/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:22:11 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/01 13:39:47 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*
static void	ft_numeric_paddnegative(t_flags *flags, t_bool negative)
{
	char		*new_str;

	if (*flags->str == '-' && flags->dot)
	{
		flags->strlen--;
		negative = TRUE;
	}
	if (flags->dot && flags->precision > flags->strlen)
	{
		new_str = malloc((flags->precision + negative + 1) * sizeof(char));
		if (!new_str)
			return ;
		if (negative)
			new_str[0] = '-';
		new_str[flags->precision + negative] = '\0';
		while (flags->strlen)
			new_str[--flags->precision + negative]
				= flags->str[--flags->strlen + negative];
		while (flags->precision)
			new_str[--flags->precision + negative] = '0';
		free(flags->str);
		flags->str = new_str;
		flags->strlen = ft_strlen(new_str);
	}
}

static void	ft_clear_zero(t_flags *flags)
{
	if (!flags->precision && flags->str[0] == '0')
		flags->str[0] = '\0';
}
*/

void	ft_convertor_d(const char *s, t_flags *flags, int *i, va_list args)
{
	char	*str;

	if (s[*i] == 'd')
	{
		str = ft_itoa(va_arg(args, int));
		if (!str)
			return ;
		flags->str = str;
		flags->type = 'd';
		ft_numeric_clear_zero(flags);
		flags->strlen = ft_strlen(flags->str);
		ft_numeric_paddnegative(flags, flags->strlen, FALSE);
		if (flags->max_width < flags->strlen)
			flags->max_width = flags->strlen;
		flags->precision = flags->max_width;
	}
}
