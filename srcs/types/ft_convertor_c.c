/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:30:03 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/16 17:46:18 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_c(const char *s, t_flags *flags_list, int *i, va_list args)
{
	char	*str;

	if (s[*i] == 'c')
	{
		str = malloc ( 2 * sizeof(char));
		str[0] = va_arg(args, int);
		str[1] = '\0';
		flags_list->str = str;
	}
}

