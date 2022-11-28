/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:36:46 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/28 11:14:11 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

t_flags	*ft_initialize_flags(void)
{
	t_flags		*flags;

	flags = malloc(sizeof(t_flags));
	if (!flags)
		return (NULL);
	flags->str = NULL;
	flags->type = '\0';
	flags->tw_chars = 0;
	flags->percent = FALSE;
	flags->dash = FALSE;
	flags->zero = FALSE;
	flags->plus = FALSE;
	flags->asterisk = FALSE;
	flags->digit = FALSE;
	flags->digits = 0;
	flags->dot = FALSE;
	flags->width = 0;
	flags->precision = 6;
	flags->hash = FALSE;
	return (flags);
}
