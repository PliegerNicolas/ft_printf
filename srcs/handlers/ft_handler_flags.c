/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:45:49 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/23 10:10:31 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_handler_flags_setter(const char *s, va_list args,
			t_flags *flags_list, int *i)
{
	while (s[*i] && (ft_isflag(s[*i]) || ft_isdigit(s[*i])))
	{
		ft_dash_setter(s, flags_list, i);
		ft_zero_setter(s, flags_list, i);
		ft_plus_setter(s, flags_list, i);
		ft_blank_setter(s, flags_list, i);
		ft_hash_setter(s, flags_list, i);
		ft_asterisk_setter(s, args, flags_list, i);
		ft_digits_setter(s, flags_list, i);
	}
}

void	ft_handler_flags(const char *s, t_flags *flags_list,
			int *i)
{
	if (s[*i] != '%')
	{
		ft_dash_convertor(s, flags_list, i);
		ft_zero_convertor(s, flags_list, i);
		ft_plus_convertor(s, flags_list, i);
		ft_blank_convertor(s, flags_list, i);
		ft_hash_convertor(s, flags_list, i);
		ft_asterisk_convertor(flags_list);
		ft_digits_convertor(flags_list);
	}
}
