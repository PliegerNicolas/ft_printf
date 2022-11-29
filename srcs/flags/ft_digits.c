/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nplieger <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:08:41 by nplieger          #+#    #+#             */
/*   Updated: 2022/11/29 16:17:04 by nplieger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	ft_digits_setter(const char *s, t_flags *flags, int *i)
{
	if (flags->asterisk)
		return ;
	flags->max_width = 0;
	flags->precision = 6;
	while (s[*i] && ft_isdigit(s[*i]))
	{
		flags->max_width *= 10;
		flags->max_width += s[(*i)++] - '0';
	}
	flags->digits = flags->max_width;
	if (s[*i] && s[*i] == '.')
	{
		flags->dot = TRUE;
		(*i)++;
		flags->precision = 0;
		if (s[*i] == '-')
			(*i)++;
		while (s[*i] && ft_isdigit(s[*i]))
		{
			flags->precision *= 10;
			flags->precision += s[(*i)++] - '0';
		}
	}
}

static void ft_digits_truncat(t_flags *flags)
{
	char	*temp;

	if (flags->dot && flags->precision)
	{
		temp = flags->str;
		flags->str = ft_substr(temp, 0, flags->precision);
		free(temp);
		flags->strlen = ft_strlen(flags->str);
	}
}

static void	ft_fillpadding(char *str, t_flags *flags, char	paddingchar)
{
	size_t		start;

	if (!flags->max_width)
		return ;
	start = flags->max_width - flags->strlen;
	while (flags->max_width > start)
		if (str[--flags->max_width] == '\0')
			str[flags->max_width] = ' ';
	while (flags->max_width)
		if (str[--flags->max_width] == '\0')
			str[flags->max_width] = paddingchar;
}

static void	ft_padding(t_flags *flags)
{
	char	*new_str;

	new_str = malloc(flags->max_width + 1 * sizeof(char));
	if (!new_str)
		return ;
	ft_bzero(new_str, flags->max_width + 1);
	if (flags->dash)
		ft_memsafecpy(new_str, flags->str, flags->max_width);
	else
		ft_memcpy_padded(new_str, flags->str, flags);
	ft_fillpadding(new_str, flags, ft_select_paddingchar(flags));
	free (flags->str);
	flags->str = new_str;
}

void	ft_digits_convertor(t_flags *flags)
{
	if (!flags->digits && !flags->dot)
		return ;
	ft_digits_truncat(flags);
	ft_padding(flags);
}
