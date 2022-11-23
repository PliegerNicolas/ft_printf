/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:47:45 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/23 13:26:55 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_s(const char *s, t_flags *flags_list, int *i, va_list args)
{
	char	*str;

	if (s[*i] == 's')
	{
		str = va_arg(args, char *);
		if (str == NULL)
		{
			if (flags_list->dot && flags_list->precision_dot < 6)
				flags_list->str = ft_strdup("");
			else
				flags_list->str = ft_strdup("(null)");
		}
		else
			flags_list->str = ft_strdup(str);
		flags_list->type = 's';
	}
}
