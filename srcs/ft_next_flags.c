/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:05:50 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/14 14:07:08 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_next_flags(t_flags *flags)
{
	flags->type = '\0';
	flags->percent = false;
	flags->dash = false;
	flags->zero = false;
	flags->plus = false;
	flags->asterisk = false;
	flags->padding_size = 0;
	flags->dot = false;
	flags->precision_value = 0;
	flags->precision_type = '\0';
	flags->hash = false;
	flags->octal = false;
	flags->hex = false;
	flags->decimal_point = false;
	flags->decimal_point_zeros = false;
}
