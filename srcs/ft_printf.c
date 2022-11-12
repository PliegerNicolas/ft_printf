/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:32:18 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/12 18:21:56 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *format, ...)
{
	va_list		args;
	t_flags		*flags;

	flags = ft_initialize_flags();
	if (!flags)
		return (0);
	va_start(args, format);
	printf("%s\n", "SUCCESS");
	va_end(args);
	free(flags);
	return (0);
}

int	main(void)
{
	ft_printf("%%%%saaaa", "string");
	return (0);
}
