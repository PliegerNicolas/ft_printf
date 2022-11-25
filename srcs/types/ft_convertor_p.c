/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:30:03 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/25 10:03:03 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_p(const char *s, t_flags *flags_list, int *i, va_list args)
{
	void	*ptr;

	if (s[*i] == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
			flags_list->str = ft_strdup("(nil)");
		else
			flags_list->str = ft_ptoa(ptr);
		flags_list->type = 'p';
	}
}
