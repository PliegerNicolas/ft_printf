/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:45:49 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/15 10:26:13 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_handler_flags(const char *s, va_list args, t_flags *flags_list,
						int *i)
{
	while (s[*i] && (ft_isflag(s[*i]) || ft_isdigit(s[*i])))
	{
		ft_convertor_dash(s, flags_list, i);
		ft_convertor_zero(s, flags_list, i);
		ft_convertor_plus(s, flags_list, i);
		ft_convertor_blank(s, flags_list, i);
		ft_convertor_hash(s, flags_list, i);
		ft_convertor_asterisk(s, args, flags_list, i);
		ft_convertor_digits(s, flags_list, i);
	}
}
