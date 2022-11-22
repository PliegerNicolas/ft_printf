/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:30:03 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/22 13:29:51 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_c(const char *s, t_flags *flags_list, int *i, va_list args)
{
	char	*str;
	char	c;

	if (s[*i] == 'c')
	{
		c = va_arg(args, int);
		str = malloc(2 * sizeof(char));
		str[0] = c;
		str[1] = '\0';
		flags_list->str = str;
		if (!str[0])
		{
			write(1, &c, 1);
			flags_list->tw_chars++;
		}
		flags_list->str_len++;
	}
}
