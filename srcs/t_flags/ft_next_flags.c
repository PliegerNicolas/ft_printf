/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:05:50 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/22 15:02:26 by nplieger         ###   ########.fr       */
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
	flags->padding = 0;
	flags->dot = FALSE;
	flags->precision = 6;
	flags->hash = FALSE;
}
