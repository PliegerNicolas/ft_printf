/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertor_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:30:03 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/15 13:53:03 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_convertor_p(const char *s, t_flags *flags, int *i, va_list args)
{
	void	*ptr;

	if (s[*i] == 'p')
	{
		ptr = va_arg(args, void *);
		if (!ptr)
			flags->str = ft_strdup("(nil)");
		else
			flags->str = ft_ptoa(ptr);
		if (!flags->str)
			return ;
		flags->type = 'p';
		flags->strlen = ft_strlen(flags->str);
		if (flags->max_width < flags->strlen)
			flags->max_width = flags->strlen;
	}
}
