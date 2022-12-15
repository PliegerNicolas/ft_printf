/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_f.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:56:25 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/15 13:55:02 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_f(const char *s, t_flags *flags, int *i, va_list args)
{
	char	*str;

	if (s[*i] == 'f' || s[*i] == 'F')
	{
		if (s[*i] == 'f')
		{
			str = ft_dtoa(va_arg(args, double), flags->precision);
			flags->type = 'f';
		}
		if (s[*i] == 'F')
		{
			str = ft_dtoa(va_arg(args, double), flags->precision);
			flags->type = 'F';
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
