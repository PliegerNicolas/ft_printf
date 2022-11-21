/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_g.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 11:02:04 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/21 16:17:49 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static void	ft_select_precision(const double nb, t_flags *flags_list)
{
	double					nb_cpy;
	unsigned long long int	ulli_nb;
	size_t					precision;

	precision = 0;
	if (nb_cpy < 0)
		nb_cpy = -nb;
	else
		nb_cpy = nb;
	ulli_nb = nb_cpy;
	while ((unsigned long long int)nb_cpy == ulli_nb && ulli_nb % 10 != 0
		&& ft_dmod(nb_cpy, 10.0) != 0)
	{
		precision++;
		nb_cpy = nb * ft_power(10, precision);
		ulli_nb = nb_cpy;
	}
	if (precision)
		precision++;
	flags_list->precision = precision;
}

void	ft_convertor_g(const char *s, t_flags *flags_list, int *i, va_list args)
{
	double					nb;
	char					*str1;
	char					*str2;

	if (s[*i] == 'g' || s[*i] == 'G')
	{
		nb = va_arg(args, double);
		ft_select_precision(nb, flags_list);
		str1 = ft_dtoa(nb, flags_list->precision);
		if (s[*i] == 'g')
			str2 = ft_sntoa(nb, flags_list->precision, false);
		else
			str2 = ft_sntoa(nb, flags_list->precision, true);
		if (str1 >= str2)
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
}
