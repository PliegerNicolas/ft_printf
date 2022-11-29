/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_e.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:02:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 10:56:01 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*
void	ft_convertor_e(const char *s, t_flags *flags_list, int *i, va_list args)
{
	if (s[*i] == 'e')
	{
		flags_list->str = ft_sntoa(va_arg(args, double), flags_list->precision,
				FALSE);
		flags_list->type = 'e';
	}
	else if (s[*i] == 'E')
	{
		flags_list->str = ft_sntoa(va_arg(args, double), flags_list->precision,
				TRUE);
		flags_list->type = 'E';
	}
}
*/

void	ft_convertor_e(const char *s, t_flags *flags, int *i, va_list args)
{
	char	*str;

	if (s[*i] == 'e' || s[*i] == 'E')
	{
		if (s[*i] == 'e')
		{
			str = ft_sntoa(va_arg(args, double), flags->precision, FALSE);
			flags->type = 'e';
		}
		if (s[*i] == 'E')
		{
			str = ft_sntoa(va_arg(args, double), flags->precision, TRUE);
			flags->type = 'E';
		}
		if (!str)
		{
			flags->type = '\0';
			return ;
		}
		flags->str = str;
		flags->strlen = ft_strlen(flags->str);
		flags->precision = flags->strlen;
	}
}
