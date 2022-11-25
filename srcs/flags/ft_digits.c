/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:08:41 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/25 10:01:39 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_digits_setter(const char *s, t_flags *flags_list, int *i)
{
	if (flags_list->asterisk)
		return ;
	flags_list->digit = TRUE;
	flags_list->width = 0;
	while (s[*i] && ft_isdigit(s[*i]))
	{
		flags_list->width *= 10;
		flags_list->width += s[(*i)++] - '0';
		flags_list->digits++;
	}
	if (s[*i] && s[*i] == '.')
	{
		flags_list->dot = TRUE;
		(*i)++;
		flags_list->precision = 0;
		if (s[*i] == '-')
			(*i)++;
		while (s[*i] && ft_isdigit(s[*i]))
		{
			flags_list->precision *= 10;
			flags_list->precision += s[(*i)++] - '0';
		}
	}
}

static void	ft_digits_convertor_string(t_flags *flags_list, size_t strlen)
{
	char	*temp;

	if (flags_list->type == '\0')
		flags_list->width--;
	if (!flags_list->width || (!flags_list->dot && strlen > flags_list->width))
		flags_list->width = strlen;
	if (flags_list->dot)
	{
		temp = flags_list->str;
		flags_list->str = ft_substr(temp, 0, flags_list->precision);
		free(temp);
	}
}

void	ft_digits_convertor(t_flags *flags_list)
{
	size_t		strlen;

	if (flags_list->digit == FALSE && flags_list->asterisk == FALSE)
		return ;
	strlen = ft_strlen(flags_list->str);
	ft_digits_convertor_string(flags_list, strlen);
	if (flags_list->width)
	flags_list->str = ft_realloc_padding(flags_list,
				ft_select_paddingchar(flags_list));
}
