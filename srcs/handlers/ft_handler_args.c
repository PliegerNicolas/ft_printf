/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:27:23 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/16 17:48:41 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_handler_args_splitter(const char *s, va_list args,
								t_flags *flags_list, int *i)
{
	if (s[*i] == 'f')
		va_arg(args, double);
	else if (s[*i] == 'e')
		va_arg(args, double);
	else if (s[*i] == 'E')
		va_arg(args, double);
	else if (s[*i] == 'g')
		va_arg(args, double);
	else if (s[*i] == 'G')
		va_arg(args, double);
	else if (s[*i] == 'p')
		va_arg(args, void *);
	else if (s[*i] == 'n')
		flags_list->tw_chars = flags_list->tw_chars;
}

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
	ft_handler_args_splitter(s, args, flags_list, i);
}
