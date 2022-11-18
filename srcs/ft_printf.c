/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:18 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/18 10:54:45 by nplieger         ###   ########.fr       */
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
	int		start;
	int		end;

	p = malloc(0);
	start = clock();
	printf("CUST : %d\n", ft_printf("{d : %d},{i : %i},{x : %x},{X : %X},{u : %u},{c : %c},{s : %s}, {f : %f},{e : %e},{E : %E},{g : %g},{G : %G},{p : %p}, %%\n", 11, 12, 13, 14, 15, 'c', "string", 1234567.123, 10.2, 10.3, 10.4, 10.5, p));
	end = clock();
	printf("time : %f\n", ((float)(end - start) / CLOCKS_PER_SEC));
	printf("\n");
	start = clock();
	printf("CUST : %d\n", printf("{d : %d},{i : %i},{x : %x},{X : %X},{u : %u},{c : %c},{s : %s}, {f : %f},{e : %e},{E : %E},{g : %g},{G : %G},{p : %p}, %%\n", 11, 12, 13, 14, 15, 'c', "string", 1234567.123, 10.2, 10.3, 10.4, 10.5, p));
	end = clock();
	printf("time : %f\n", ((float)(end - start) / CLOCKS_PER_SEC));
	free(p);
	return (0);
}
