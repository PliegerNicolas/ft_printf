/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:30:03 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/15 13:55:31 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_c(const char *s, t_flags *flags, int *i, va_list args)
{
	char			*str;
	unsigned char	c;
	size_t			size;

	if (s[*i] == 'c')
	{
		size = 0;
		c = (unsigned char)va_arg(args, int);
		if (c != '\0')
		{
			flags->type = 'c';
			size++;
		}
		str = malloc(size + 1 * sizeof(char));
		if (!str)
			return ;
		flags->strlen = size;
		if (size)
			str[size--] = '\0';
		str[size] = c;
		flags->str = str;
		if (!flags->dot)
			flags->precision = 1;
	}
}
