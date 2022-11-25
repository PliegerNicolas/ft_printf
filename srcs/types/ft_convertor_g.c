/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_g.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:02:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/25 09:56:19 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_g_format_selector(const double nb, t_flags *flags_list, const char *s, int *i)
{
	char	*str1;
	char	*str2;

	str1 = ft_dtoa(nb, flags_list->precision);
	if (s[*i] == 'g')
		str2 = ft_sntoa(nb, flags_list->precision, FALSE);
	else
		str2 = ft_sntoa(nb, flags_list->precision, TRUE);
	if (ft_strlen(str1) >= ft_strlen(str2))
	{
		flags_list->str = str1;
		free(str2);
	}
	else
	{
		flags_list->str = str2;
		free(str1);
	}
}

void	ft_convertor_g(const char *s, t_flags *flags_list, int *i, va_list args)
{
	if (s[*i] == 'g')
		flags_list->type = 'g';
	if (s[*i] == 'G')
		flags_list->type = 'G';
	if (s[*i] == 'g' || s[*i] == 'G')
	{
		ft_g_format_selector(va_arg(args, double), flags_list, s, i);
		flags_list->precision = 0;
		flags_list->dot = FALSE;
	}
}
