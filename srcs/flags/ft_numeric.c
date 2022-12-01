/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numeric.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:27:20 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/01 13:38:34 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_numeric_paddnegative(t_flags *flags, size_t	strlen, t_bool negative)
{
	char		*new_str;

	if (*flags->str == '-' && flags->dot)
	{
		strlen--;
		negative = TRUE;
	}
	if (flags->dot && flags->precision > strlen)
	{
		new_str = malloc((flags->precision + negative + 1) * sizeof(char));
		if (!new_str)
			return ;
		if (negative)
			new_str[0] = '-';
		new_str[flags->precision + negative] = '\0';
		while (strlen)
			new_str[--flags->precision + negative]
				= flags->str[--strlen + negative];
		while (flags->precision)
			new_str[--flags->precision + negative] = '0';
		free(flags->str);
		flags->str = new_str;
		flags->strlen = ft_strlen(new_str);
	}
}

void	ft_numeric_clear_zero(t_flags *flags)
{
	if (flags->dot && !flags->precision && flags->str[0] == '0')
		flags->str[0] = '\0';
}
