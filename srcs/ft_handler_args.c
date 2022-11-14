/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:27:23 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/14 15:32:22 by nplieger         ###   ########.fr       */
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
	if (s[*i] == 'd' || s[*i] == 'i')
		ft_convertor_d(va_arg(args, int), flags_list);
	else if (s[*i] == 'o')
		va_arg(args, int);
	else if (s[*i] == 'x')
		va_arg(args, int);
	else if (s[*i] == 'X')
		va_arg(args, int);
	else if (s[*i] == 'u')
		va_arg(args, unsigned int);
	else if (s[*i] == 'c')
		va_arg(args, int);
	else if (s[*i] == 's')
		va_arg(args, char *);
	ft_handler_args_splitter(s, args, flags_list, i);
}
