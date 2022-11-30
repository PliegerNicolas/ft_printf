/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:22:11 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/30 14:45:21 by nplieger         ###   ########.fr       */
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
		flags->type = 'd';
		flags->strlen = ft_strlen(flags->str);
		if (ft_numeric_digits(flags))
			return ;
		if (ft_numeric_precision(flags))
			return ;
	}
}
