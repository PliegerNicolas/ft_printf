/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_flags.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:45:49 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/14 14:18:47 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_handler_flags_asterisk(const char *s, t_flags *flags_list, int *i)
{
	(*i)++;
	if (s[*i] == 'o')
		flags_list->octal = true;
	else if (s[*i] == 'x' || s[*i] == 'X')
		flags_list->hex = true;
	else if (s[*i] == 'e' || s[*i] == 'E' || s[*i] == 'f')
		flags_list->decimal_point = true;
	else if (s[*i] == 'g' || s[*i] == 'G')
		flags_list->decimal_point_zeros = true;
}

void	ft_handler_flags(const char *s, t_flags *flags_list, int *i)
{
	int		units;

	units = 1;
	if (!ft_isflag(s[*i]))
		return ;
	if (s[*i] == '-')
		flags_list->dash = true;
	else if (s[*i] == '0')
		flags_list->zero = true;
	else if (s[*i] == '+')
		flags_list->plus = true;
	else if (s[*i] == ' ')
		flags_list->blank = true;
	else if (s[*i] == '*')
		flags_list->asterisk = true;
	else if (s[*i] == '#')
		ft_handler_flags_asterisk(s, flags_list, i);
	while (ft_isdigit(s[*i]))
	{
		flags_list->padding_size += ft_isdigit(s[(*i)++]) * units;
		units *= 10;
	}
}

