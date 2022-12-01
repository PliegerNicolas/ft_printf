/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initialize_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:36:46 by nplieger          #+#    #+#             */
/*   Updated: 2022/12/01 16:45:16 by nplieger         ###   ########.fr       */
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
	flags->blank = FALSE;
	flags->asterisk = FALSE;
	flags->digits = 0;
	flags->dot = FALSE;
	flags->strlen = 0;
	flags->max_width = 0;
	flags->extra_rightpadd = 0;
	flags->precision = 0;
	flags->hash = FALSE;
	flags->hash_type = '\0';
	return (flags);
}
