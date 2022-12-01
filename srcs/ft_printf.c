/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:18 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/01 13:41:59 by nplieger         ###   ########.fr       */
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
	// ret : "0000000042", return : 10
	printf("->COUNT : %d\n", printf("%010d", 42));
	printf("->COUNT : %d\n", ft_printf("%010d", 42));

	// ret : "00000000", return : 8
	printf("->COUNT : %d\n", printf("%-1.8d", 0));
	printf("->COUNT : %d\n", ft_printf("%-1.8d", 0));
	// ret : "-1234", return : 5
	printf("->COUNT : %d\n", printf("%.3d", -1234));
	printf("->COUNT : %d\n", ft_printf("%.3d", -1234));
	// ret : "0", return : 1
	printf("->COUNT : %d\n", printf("%d", 0));
	printf("->COUNT : %d\n", ft_printf("%d", 0));

	printf("\n");

	// ret
	printf("->COUNT : %d\n", printf("%042.2d", 42000));
	printf("->COUNT : %d\n", ft_printf("%042.2d", 42000));
	// ret
	printf("->COUNT : %d\n", printf("%042.20d", 42000));
	printf("->COUNT : %d\n", ft_printf("%042.20d", 42000));
	// ret
	printf("->COUNT : %d\n", printf("%030d", (int)-2147483648));
	printf("->COUNT : %d\n", ft_printf("%030d", (int)-2147483648));
	// ret
	printf("->COUNT : %d\n", printf("%020d", -42000));
	printf("->COUNT : %d\n", ft_printf("%020d", -42000));

	printf("\n");

	// ret : "w    ", return : 5 || aka max_width = 5, strlen 1, precision = 0
	printf("->COUNT : %d\n", printf("%-5c", 'w'));
	printf("->COUNT : %d\n", ft_printf("%-5c", 'w'));
	// ret : "b", return : 1 || aka max_width = 1, strlen 1, precision = 0
	printf("->COUNT : %d\n", printf("%-1c", 'b'));
	printf("->COUNT : %d\n", ft_printf("%-1c", 'b'));
	// ret : "00010     ", return : 10 || aka max_width = 10, strlen 5, precision = 5
	printf("->COUNT : %d\n", printf("%-10.5d", 10));
	printf("->COUNT : %d\n", ft_printf("%-10.5d", 10));
	// ret : "          ", return : 10 || aka max_width = 10, strlen 1, precision = 0
	printf("->COUNT : %d\n", printf("%-10.d", 0));
	printf("->COUNT : %d\n", ft_printf("%-10.d", 0));

	printf("\n");

	// ret : "", return : 0 || aka max_width = 1, strlen 1, precision = 0
	printf("->COUNT : %d\n", printf("%.d", 0));
	printf("->COUNT : %d\n", ft_printf("%.d", 0));
	// ret : "420000", return : 6 || aka max_width = 6, strlen 6, precision = 0
	printf("->COUNT : %d\n", printf("%.3d", 420000));
	printf("->COUNT : %d\n", ft_printf("%.3d", 420000));
	// ret : "", return : 6 || aka max_width = 1, strlen 1, precision = 0
	printf("->COUNT : %d\n", printf("%.d", 0));
	printf("->COUNT : %d\n", ft_printf("%.d", 0));
	// ret : "-01234", return : 6 || aka max_width = 6, strlen 5, precision = 5
	printf("->COUNT : %d\n", printf("%.5d", -1234));
	printf("->COUNT : %d\n", ft_printf("%.5d", -1234));
	// ret : "-001", return : 4 || aka max_width = 4, strlen = 3, precision = 3
	printf("->COUNT : %d\n", printf("%.3d", -1));
	printf("->COUNT : %d\n", ft_printf("%.3d", -1));
	// ret : "0032", return : 4 || aka max_width = 4, strlen = 4, precision = 4
	printf("->COUNT : %d\n", printf("%.4d", 32));
	printf("->COUNT : %d\n", ft_printf("%.4d", 32));
	// ret : "03", return : 2 || aka max_width = 2, strlen = 2, precision = 2
	printf("->COUNT : %d\n", printf("%.2d", 3));
	printf("->COUNT : %d\n", ft_printf("%.2d", 3));

	printf("\n");

	// ret : "-42000", return : 6
	printf("->COUNT : %d\n", printf("%2d", -42000));
	printf("->COUNT : %d\n", ft_printf("%2d", -42000));
	// ret : "0000000042", return : 10
	printf("->COUNT : %d\n", printf("%10d", 42));
	printf("->COUNT : %d\n", ft_printf("%10d", 42));
	// ret : "000000000000000000000000000000000000042000", return : 42
	printf("->COUNT : %d\n", printf("%42d", 42000));
	printf("->COUNT : %d\n", ft_printf("%42d", 42000));
	// ret : "              -42000", return : 20
	printf("->COUNT : %d\n", printf("%20d", -42000));
	printf("->COUNT : %d\n", ft_printf("%20d", -42000));
	free(p);
	return (0);
}
