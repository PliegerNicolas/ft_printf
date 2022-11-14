/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:36:46 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/14 14:06:59 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_flags	*ft_initialize_flags(void)
{
	t_flags		*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->type = '\0';
	flags->tw_chars = 0;
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
	return (flags);
}
