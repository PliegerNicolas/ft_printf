/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:05:50 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 10:28:20 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_next_flags(t_flags *flags)
{
	if (flags->str)
		free(flags->str);
	flags->str = '\0';
	flags->type = '\0';
	flags->percent = FALSE;
	flags->dash = FALSE;
	flags->zero = FALSE;
	flags->plus = FALSE;
	flags->asterisk = FALSE;
	flags->digits = 0;
	flags->dot = FALSE;
	flags->strlen = 0;
	flags->max_width = 0;
	flags->precision = 0;
	flags->hash = FALSE;
}
