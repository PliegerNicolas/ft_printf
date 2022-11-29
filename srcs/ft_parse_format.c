/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 10:23:49 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 11:36:24 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_parse_format(const char *s, va_list args, t_flags *flags)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (ft_handler_percent(s, flags, &i))
		{
			ft_handler_flags_setter(s, args, flags, &i);
			ft_handler_args(s, args, flags, &i);
			ft_handler_flags(s, flags, &i);
			if (flags->str)
			{
				ft_putstrc(flags->str, flags, &i);
				ft_next_flags(flags);
			}
		}
		else
			ft_putcharc(s[i++], flags);
	}
	return (flags->tw_chars);
}
