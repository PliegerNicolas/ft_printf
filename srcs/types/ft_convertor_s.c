/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:47:45 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/30 14:54:22 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_set_sflags(t_flags *flags)
{
	if (flags->digits < flags->strlen)
		flags->max_width = flags->strlen;
	if (flags->dot)
	{
		if (flags->strlen > flags->precision)
			flags->strlen = flags->precision;
		flags->max_width = flags->digits;
		if (flags->strlen > flags->max_width)
			flags->max_width = flags->strlen;
	}
}

void	ft_convertor_s(const char *s, t_flags *flags, int *i, va_list args)
{
	char		*str;

	if (s[*i] == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
		{
			if (flags->dot && flags->precision < 6)
				flags->str = ft_strdup("");
			else
				flags->str = ft_strdup("(null)");
		}
		else
			flags->str = ft_strdup(str);
		if (!flags->str)
			return ;
		flags->type = 's';
		flags->strlen = ft_strlen(flags->str);
		ft_set_sflags(flags);
	}
}
