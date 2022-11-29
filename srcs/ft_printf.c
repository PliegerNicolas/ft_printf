/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:18 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 17:41:15 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <time.h>

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
	printf("COUNT : %d\n", printf("%.5d", -1234));
	printf("COUNT : %d\n", ft_printf("%.5d", -1234));
	printf("COUNT : %d\n", printf("%.11d", (int)-2147483648));
	printf("COUNT : %d\n", ft_printf("%.11d", (int)-2147483648));
	printf("COUNT : %d\n", printf("%1c", '\0'));
	printf("COUNT : %d\n", ft_printf("%1c", '\0'));
	printf("COUNT : %d\n", printf("%.2d", 3));
	printf("COUNT : %d\n", ft_printf("%.2d", 3));
	printf("COUNT : %d\n", printf("%.13d", (int)-2147483648));
	printf("COUNT : %d\n", ft_printf("%.13d", (int)-2147483648));
	printf("COUNT : %d\n", printf("%.3d", 420000));
	printf("COUNT : %d\n", ft_printf("%.3d", 420000));
	printf("COUNT : %d\n", printf("%.3d", -1234));
	printf("COUNT : %d\n", ft_printf("%.3d", -1234));
	free(p);
	return (0);
}
