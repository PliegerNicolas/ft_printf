/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:36:46 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/23 14:13:26 by nplieger         ###   ########.fr       */
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
	flags->width = 0;
	flags->dot = FALSE;
	flags->precision = 0;
	flags->precision_dot = 6;
	flags->hash = FALSE;
	return (flags);
}
