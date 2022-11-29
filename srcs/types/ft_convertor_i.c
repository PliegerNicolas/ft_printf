/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_i.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:22:38 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 13:41:30 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*
void	ft_convertor_i(const char *s, t_flags *flags_list, int *i, va_list args)
{
	if (s[*i] == 'i')
	{
		flags_list->str = ft_itoa(va_arg(args, int));
		flags_list->type = 'i';
		ft_int_flagger(flags_list, ft_strlen(flags_list->str));
	}
}
*/

void	ft_convertor_i(const char *s, t_flags *flags, int *i, va_list args)
{
	char	*str;

	if (s[*i] == 'i')
	{
		str = ft_itoa(va_arg(args, int));
		if (!str)
			return ;
		flags->str = str;
		flags->strlen = ft_strlen(flags->str);
		flags->type = 'i';
		if (flags->dot)
		{
			flags->dot = FALSE;
			flags->precision = 0;
		}
		if (flags->max_width < flags->strlen)
			flags->max_width = flags->strlen;
	}
}
