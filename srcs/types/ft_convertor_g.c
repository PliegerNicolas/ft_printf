/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_g.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:02:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/15 13:54:40 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*
	G DOESN'T WORK CORRECTLY.
*/

static void	ft_g_format_selector(const double nb, t_flags *flags,
						const char *s, int *i)
{
	char	*str1;
	char	*str2;

	str1 = ft_dtoa(nb, flags->precision);
	if (!str1)
		return ;
	if (s[*i] == 'g')
		str2 = ft_sntoa(nb, flags->precision, FALSE);
	else
		str2 = ft_sntoa(nb, flags->precision, TRUE);
	if (!str2)
		return ;
	if (ft_strlen(str1) >= ft_strlen(str2))
	{
		flags->str = str1;
		free(str2);
	}
	else
	{
		flags->str = str2;
		free(str1);
	}
}

void	ft_convertor_g(const char *s, t_flags *flags, int *i, va_list args)
{
	if (s[*i] == 'g' || s[*i] == 'G')
	{
		if (s[*i] == 'g')
			flags->type = 'g';
		if (s[*i] == 'G')
			flags->type = 'G';
		if (s[*i] == 'g' || s[*i] == 'G')
		{
			ft_g_format_selector(va_arg(args, double), flags, s, i);
			flags->strlen = ft_strlen(flags->str);
			flags->precision = flags->strlen;
		}
	}
}
