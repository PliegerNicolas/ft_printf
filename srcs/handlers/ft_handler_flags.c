/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:45:49 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/01 16:22:18 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_handler_flags_setter(const char *s, va_list args, t_flags *flags,
							int *i)
{
	while (s[*i] && (ft_isflag(s[*i]) || ft_isdigit(s[*i])))
	{
		ft_dash_setter(s, flags, i);
		ft_zero_setter(s, flags, i);
		ft_plus_setter(s, flags, i);
		ft_blank_setter(s, flags, i);
		ft_hash_setter(s, flags, i);
		ft_asterisk_setter(s, args, flags, i);
		ft_digits_setter(s, flags, i);
	}
}

void	ft_handler_flags(const char *s, t_flags *flags, int *i)
{
	if (s[*i] != '%')
	{
		//ft_dash_convertor(flags);
		//ft_zero_convertor(flags);
		ft_blank_convertor(flags);
		ft_plus_convertor(flags);
		//ft_hash_convertor(flags);
		//ft_asterisk_convertor(flags);
		ft_digits_convertor(flags);
	}
}
