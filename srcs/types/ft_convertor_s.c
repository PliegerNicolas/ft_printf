/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:47:45 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 15:55:35 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

/*
void	ft_convertor_s(const char *s, t_flags *flags_list, int *i, va_list args)
{
	char	*str;

	if (s[*i] == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
		{
			if (flags_list->dot && flags_list->precision < 6)
				flags_list->str = ft_strdup("");
			else
				flags_list->str = ft_strdup("(null)");
		}
		else
			flags_list->str = ft_strdup(str);
		flags_list->type = 's';
	}
}
*/

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
}
