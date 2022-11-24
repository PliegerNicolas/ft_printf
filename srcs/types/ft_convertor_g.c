/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_g.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:02:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/24 15:15:50 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_g(const char *s, t_flags *flags_list, int *i, va_list args)
{
	double	nb;
	char	*str1;
	char	*str2;

	if (s[*i] == 'g')
		flags_list->type = 'g';
	if (s[*i] == 'G')
		flags_list->type = 'G';
	if (s[*i] == 'g' || s[*i] == 'G')
	{
		nb = va_arg(args, double);
		str1 = ft_dtoa(nb, flags_list->precision);
		if (s[*i] == 'g')
			str2 = ft_sntoa(nb, flags_list->precision, FALSE);
		else
			str2 = ft_sntoa(nb, flags_list->precision, FALSE);
		if (str1 >= str2)
		{
			flags_list->str = str1;
			flags_list->str = str1;
			free (str2);
		}
		else
		{
			flags_list->str = str2;
			free(str1);
		}
	}
}
