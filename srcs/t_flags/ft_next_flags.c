/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:05:50 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/15 15:42:00 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_next_flags(t_flags *flags)
{
	if (flags->str)
		free(flags->str);
	flags->str = '\0';
	flags->percent = false;
	flags->dash = false;
	flags->zero = false;
	flags->plus = false;
	flags->asterisk = false;
	flags->padding = 0;
	flags->dot = false;
	flags->precision_value = 0;
	flags->precision_type = '\0';
	flags->hash = false;
	flags->octal = false;
	flags->hex = false;
	flags->decimal_point = false;
	flags->decimal_point_zeros = false;
}
