/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:27:23 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 10:47:41 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_handler_args(const char *s, va_list args, t_flags *flags, int *i)
{
	if (!ft_istype(s[*i]))
		return ;
	ft_convertor_d(s, flags, i, args);
	ft_convertor_i(s, flags, i, args);
	ft_convertor_o(s, flags, i, args);
	ft_convertor_x(s, flags, i, args);
	ft_convertor_u(s, flags, i, args);
	ft_convertor_c(s, flags, i, args);
	ft_convertor_s(s, flags, i, args);
	ft_convertor_f(s, flags, i, args);
	ft_convertor_e(s, flags, i, args);
	ft_convertor_g(s, flags, i, args);
	ft_convertor_p(s, flags, i, args);
	if (s[*i] == 'n')
		flags->tw_chars = flags->tw_chars;
}
