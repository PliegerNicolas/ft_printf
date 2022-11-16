/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:18 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/16 17:25:02 by nplieger         ###   ########.fr       */
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
	void	*p;

	p = malloc(0);
	printf("CUST : %d\n", ft_printf("%d%i%x%X%u%c%s%f%e%E%g%G%p%%\n", 11, 12, 13,
			14, 15, 'c', "string", 10.1, 10.2, 10.3, 10.4, 10.5, p));
	printf("\n");
	printf("CUST : %d\n", printf("%d%i%x%X%u%c%s%f%e%E%g%G%p%%\n", 11, 12, 13,
			14, 15, 'c', "string", 10.1, 10.2, 10.3, 10.4, 10.5, p));
	free(p);
	return (0);
}
