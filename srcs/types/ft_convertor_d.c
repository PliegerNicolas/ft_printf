/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:22:11 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 13:40:25 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*
void	ft_convertor_d(const char *s, t_flags *flags_list, int *i, va_list args)
{
	size_t		strlen;

	if (s[*i] == 'd')
	{
		flags_list->str = ft_itoa(va_arg(args, int));
		flags_list->type = 'd';
		strlen = ft_strlen(flags_list->str);
		ft_int_flagger(flags_list, strlen);
	}
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
		flags->strlen = ft_strlen(flags->str);
		flags->type = 'd';
		if (flags->dot)
		{
			flags->dot = FALSE;
			flags->precision = 0;
		}
		if (flags->max_width < flags->strlen)
			flags->max_width = flags->strlen;
	}
}
