/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:27:23 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/21 17:23:49 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_handler_args(const char *s, va_list args, t_flags *flags_list,
			int *i)
{
	if (!ft_istype(s[*i]))
		return ;
	ft_convertor_d(s, flags_list, i, args);
	ft_convertor_i(s, flags_list, i, args);
	ft_convertor_o(s, flags_list, i, args);
	ft_convertor_x(s, flags_list, i, args);
	ft_convertor_u(s, flags_list, i, args);
	ft_convertor_c(s, flags_list, i, args);
	ft_convertor_s(s, flags_list, i, args);
	ft_convertor_f(s, flags_list, i, args);
	ft_convertor_e(s, flags_list, i, args);
	ft_convertor_g(s, flags_list, i, args);
	ft_convertor_p(s, flags_list, i, args);
	if (s[*i] == 'n')
		flags_list->tw_chars = flags_list->tw_chars;
}
