/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:18 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/15 12:14:23 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_flags		*flags_list;
	int			tw_chars;

	tw_chars = 0;
	flags_list = ft_initialize_flags();
	if (!flags_list)
		return (0);
	va_start(args, format);
	tw_chars += ft_parse_format(format, args, flags_list);
	va_end(args);
	free(flags_list);
	return (tw_chars);
}

int	main(void)
{
	printf("CUST : %d\n", ft_printf("CUST : %%%%%-*d%oaaaa\n", 10, 10, -2));
	printf("\n");
	printf("ORIG : %d\n", printf("ORIG : %%%%%-*d%oaaaa\n", 10, 10, -2));
	return (0);
}
